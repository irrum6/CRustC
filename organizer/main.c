#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <time.h>

#include "read.h"
#include "event.h"

bool matches(char *str1, char *str2, int len);
time_t getInputTime(void);
int typer(char *type, int min, int max);
void actOnCommand(char *command, event *events, long size);
void writeMenu();

void onAddEvent(event *events, long size);
void onEditEvent(event *events, long size);
void proceedEditEvent(event *events, long index, long size);
void onDeleteEvent(event *events, long size);

const long MAX_RECORDS_NUMBER = 16384;

int main(int argc, char **argv)
{
    const char *restrict _testfn = "gelava.bdef";

    if (argc > 1)
    {
        //rewrite file hah
        const char *WRITE_BINARY = "wb";
        FILE *fp = fopen(_testfn, WRITE_BINARY);
        writeFileHeader(fp);
        fclose(fp);
    }

    long count = readFileAndCount(_testfn);

    printf("%d records were found.\n", count);

    long num = 16; //at least 16
    if (count > 0)
    {
        if (count + 4 < MAX_RECORDS_NUMBER)
        {
            num = count + 4;
        }
    }

    event *events = malloc(sizeof(event) * num);
    initZero(events, num);

    if (count > 0)
    {
        readFromFile(_testfn, events, count);
    }

    writeMenu();
    char command[7];
    bool notExit = true;
    while (notExit)
    {
        if (matches(command, "exit", 4))
        {
            notExit = false;
            continue;
        }

        int res = stdReadLine(3, 7, command);
        if (res < 0)
        {
            printf("short, type again\n");
            continue;
        }
        actOnCommand(command, events, num);
    }
    long last = getFreeIndex(events, num);
    writeToFile(_testfn, events, last);
    freeEvents(events, num); //out of loop free pointer
    return 0;
}

bool matches(char *str1, char *str2, int len)
{
    if (len < 0)
        return false;
    return (strncmp(str1, str2, len) == 0);
}
void actOnCommand(char *command, event *events, long size)
{
    if (matches(command, "help", 4))
    {
        writeMenu();
    }
    if (matches(command, "add", 3))
    {
        onAddEvent(events, size);
    }
    if (matches(command, "edit", 4))
    {
        onEditEvent(events, size);
    }
    if (matches(command, "list", 4))
    {
        printEvents(events, size);
    }
    if (matches(command, "upco", 4))
    {
        // printUpcommingEvents(events, size);
    }
    if (matches(command, "delete", 6))
    {
        onDeleteEvent(events, size);
    }
    return;
}
void writeMenu()
{
    printf("commands available:\n");
    printf("list - lists all events\n");
    printf("help - displays this menu\n");
    printf("add - add an event\n");
    printf("edit - edit an event\n");
    printf("exit - exit the program\n");
    printf("delete - delete an event\n");
    printf("upco - list upcomming events\n");
}

int typer(char *type, int min, int max)
{
    int x = -1;
    printf("type %s\n", type);
    scanf("%d", &x);
    if (x > max || x < min)
    {
        printf("not valid %s\n", type);
        return -1;
    }
    return x;
}
void onAddEvent(event *events, long size)
{
    time_t time = getInputTime();
    if (time == 0)
    {
        return;
    }
    long index = searchByTime(events, time, size);

    if (index != -1)
    {
        char ch;
        printf("Event is on calendar. You want to edit? Y or N\n");
        ch = getchar();
        if (ch != 'Y')
        {
            return;
        }
        onEditEvent(events, size);
    }
    long index2 = getFreeIndex(events, size);
    getchar(); //discard enter
    char *msg = "Adding Event...";
    char *msg2 = "Event was added.";
    editEvent(events, index2, time, msg, msg2);
}
void onPrintUpcommingEvents(event *events, long size)
{
    int next = 30;
    printf("displaying events in next %d days", next);

    time_t t = time(NULL);
    struct tm *c = localtime(&t);

    c->tm_mon = c->tm_mon + 1;

    time_t t1 = mktime(c);

    printUpcommingEvents(events, t, t1, size);
}
void onEditEvent(event *events, long size)
{
    int index;
    printf("type index\n");
    scanf("%d", &index);
    if (index > size || index < 0)
    {
        printf("not valid index\n");
        return;
    }
    getchar(); //discard enter
    proceedEditEvent(events, index, size);
}
time_t getInputTime(void)
{
    int mon, day, hour, min;
    mon = typer("month", 0, 11);
    if (mon < 0)
    {
        return 0;
    }
    day = typer("day", 1, 31);
    if (day < 1)
    {
        return 0;
    }
    hour = typer("hour", 0, 23);
    if (hour < 0)
    {
        return 0;
    }
    min = typer("minute", 0, 59);
    if (min < 0)
    {
        return 0;
    }
    time_t t = time(NULL);
    struct tm *c = localtime(&t);

    c->tm_mon = mon;
    c->tm_mday = day;
    c->tm_hour = hour;
    c->tm_min = min;
    c->tm_sec = 0;

    t = mktime(c);

    return t;
}

void proceedEditEvent(event *events, long index, long size)
{
    char ch;
    char *msg = "Editing Event...";
    char *msg2 = "Event was edited.";

    printf("You wan't to keep time? Y/n\n");
    ch = getchar();
    if (ch != 'Y')
    {
        editEvent(events, index, events[index].time, msg, msg2);
        return;
    }
    time_t time = getInputTime();
    long index2 = searchByTime(events, time, size);
    if (index2 != -1)
    {
        printf("time is taken\n");
        return;
    }
    editEvent(events, index, time, msg, msg2);
}

void onDeleteEvent(event *events, long size)
{
    int index;
    printf("type index\n");
    scanf("%d", &index);
    if (index > size || index < 0)
    {
        printf("not valid index\n");
        return;
    }
    getchar(); //discard enter
    deleteEvent(events, index);
}