#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "read.h"
#include "event.h"

#include <time.h>

/**
 * @param event* events
 * @param long size //size of events array
 */
void printEvents(event *events, long size)
{
    struct tm *cal;
    for (int i = 0; i < size; i++)
    {
        if (events[i].desclen < 0 ||
            0 == events[i].time)
        {
            continue;
        }
        printf("Event %d\n", i);
        cal = localtime(&events[i].time);
        printf("Month Day:%d-%d\n", cal->tm_mon, cal->tm_mday);
        printf("HourMinute- %d:%d\n", cal->tm_hour, cal->tm_min);
        printf("Name:%s\n", events[i].name);
        printf("Description:%s\n", events[i].desc);
    }
}
/**
 * @param event* events
 * @param time_t t //period start
 * @param time_t t2 //period end
 * @param long size //size of events array
 */
void printUpcommingEvents(event *events, time_t t, time_t t2, long size)
{
    struct tm *cal;
    for (int i = 0; i < size; i++)
    {
        if (events[i].desclen < 0)
        {
            continue;
        }
        if (events[i].time < t || events[i].time > t2)
        {
            continue;
        }
        printf("Event %d\n", i);
        cal = localtime(&events[i].time);
        printf("Month Day:%d%d\n", cal->tm_mon, cal->tm_mday);
        printf("HourMinute- %d:%d\n", cal->tm_hour, cal->tm_min);
        printf("Name:%s\n", events[i].name);
        printf("Description:%s\n", events[i].desc);
    }
}
void initZero(event *events, long size)
{
    for (long i = 0; i < size; i++)
    {
        zeroAnEvent(events, i);
    }
}
void zeroAnEvent(event *events, long index)
{
    events[index].time = 0;
    events[index].desc = NULL;
    events[index].name = NULL;
}
long getFreeIndex(event *events, long size)
{
    for (long i = 0; i < size; i++)
    {
        if (0 == events[i].time)
        {
            return i;
        }
    }
    if (size * 2 < __LONG_MAX__)
    {
        size *= 2;
    }
    else if (size + 1 < __LONG_MAX__)
    {
        size++;
    }
    else
    {
        return -1;
    }
    //if no free space was found
    events = (event *)realloc(events, sizeof(event) * size);
    if (events == NULL)
    {
        return -1;
    }
}

long searchByTime(event *events, time_t t, long size)
{
    for (long i = 0; i < size; i++)
    {
        if (events[i].time == t)
        {
            return i;
        }
    }
    return -1;
}

void editEvent(event *events, long index, time_t time, char *msg, char *msg2)
{
    printf("%s\n", msg);
    if (index < 0)
    {
        printf("what, no free index in list?");
        return;
    }
    const int MAX_NAME_LEN = 40;
    const int MAX_DESC_LEN = 480;

    char *name = malloc(sizeof(char) * MAX_NAME_LEN);
    char *desc = malloc(sizeof(char) * MAX_DESC_LEN);

    if (name == NULL || desc == NULL)
    {
        printf("allocation failed, exiting.");
        return;
    }

    printf("type name max %d characters\n", MAX_NAME_LEN);
    stdReadLine(3, MAX_NAME_LEN, name);
    printf("type description max %d characters\n", MAX_DESC_LEN);
    stdReadLine(3, MAX_DESC_LEN, desc);

    events[index].namelen = strlen(name);
    events[index].name = name;
    events[index].desclen = strlen(desc);
    events[index].desc = desc;
    events[index].time = time;
    printf("%s\n", msg2);
}

void deleteEvent(event *events, long index)
{
    //other fields don't matter;
    free(events[index].name);
    events[index].name = NULL;
    free(events[index].desc);
    events[index].desc = NULL;
    events[index].desclen = -128;
}
void freeEvents(event *events, long size)
{
    for (long index = 0; index < size; index++)
    {
        free(events[index].name);
        events[index].name = NULL;
        free(events[index].desc);
        events[index].desc = NULL;
    }
    free(events);
    events = NULL;
}
/**
* this reads files and counts records.
* @param char fn //filename
* @returns long count
*/
long readFileAndCount(const char *restrict fn)
{
    long count = 0;
    const char *READ_BINARY = "rb";
    FILE *fp = fopen(fn, READ_BINARY);
    int fh = checkFileHeader(fp);
    if (fh != 0)
    {
        goto failexit;
    }
    fread(&count, sizeof(long), 1, fp);
    if (feof(fp))
    {
        goto failexit;
    }
    fclose(fp);
    return count;
failexit:
    fclose(fp);
    return count;
}

void readFromFile(const char *restrict fn, event *events, long count)
{
    const char *READ_BINARY = "rb";
    FILE *fp = fopen(fn, READ_BINARY);
    int fh = checkFileHeader(fp);
    if (fh != 0)
    {
        fclose(fp);
        return;
    }
    //read size and discard;
    long _size;
    fread(&_size, sizeof(long), 1, fp);
    for (long i = 0; i < count; i++)
    {
        readRecordFromfile(events, i, fp);
    }

    fclose(fp);
    return;
}
void readRecordFromfile(event *events, long index, FILE *fp)
{
    time_t cal;
    fread(&cal, sizeof(time_t), 1, fp);
    if (feof(fp))
    {
        fclose(fp);
        return;
    }

    long nlen; //name length
    fread(&nlen, sizeof(long), 1, fp);

    char *name = malloc(sizeof(char) * nlen);
    fread(name, sizeof(char), nlen, fp);
    printf("%s\n", name);

    long dlen;
    fread(&dlen, sizeof(long), 1, fp);

    char *desc = malloc(sizeof(char) * dlen);
    fread(desc, sizeof(char), dlen, fp);

    events[index].name = name;
    events[index].desc = desc;
    events[index].time = cal;
    events[index].namelen = nlen;
    events[index].desclen = dlen;
}

int writeToFile(const char *restrict fn, event *events, long size)
{
    const char *WRITE_BINARY = "wb";

    FILE *fp = fopen(fn, WRITE_BINARY);
    int whr = writeFileHeader(fp);
    if (whr != 0)
    {
        return whr;
    }
    //then write total number of records
    fwrite(&size, sizeof(long), 1, fp);

    long i = 0;
    while (i < size)
    {
        time_t cale = events[i].time;
        fwrite(&cale, sizeof(time_t), 1, fp);
        long lele = events[i].namelen;
        fwrite(&lele, sizeof(long), 1, fp);
        char *lo = events[i].name;
        fwrite(lo, sizeof(char), lele, fp);
        lele = events[i].desclen;
        fwrite(&lele, sizeof(long), 1, fp);
        lo = events[i].desc;
        fwrite(lo, sizeof(char), lele, fp);
        i++;
    }

    fclose(fp);
    return i;
}

const int MAGIC_NUMBERS[] = {316, 1, 29};

int checkFileHeader(FILE *fp)
{
    if (fp == NULL)
    {
        printf("null pointer to file");
        return -1;
    }
    int x[3];
    fread(x, sizeof(int), 3, fp);

    if (x[0] != MAGIC_NUMBERS[0] ||
        x[1] != MAGIC_NUMBERS[1] ||
        x[2] != MAGIC_NUMBERS[2])
    {
        printf("incorect header, exiting\n");
        return -2;
    }

    return 0;
}

int writeFileHeader(FILE *fp)
{
    if (fp == NULL)
    {
        printf("null pointer to file");
        return -1;
    }
    fwrite(&MAGIC_NUMBERS, sizeof(int), 3, fp);
    return 0;
}