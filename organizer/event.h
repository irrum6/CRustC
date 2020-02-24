#include <time.h>

typedef struct _event
{
    time_t time;
    char *name;
    long namelen;
    char *desc;
    long desclen;

} event;

void initZero(event *events, long size);
void zeroAnEvent(event *events, long index);
void printEvents(event *events, long size);
void printUpcommingEvents(event *events, time_t t, time_t t2, long size);

void editEvent(event *events, long index, time_t time, char *msg, char *msg2);
void deleteEvent(event *events, long index);
void freeEvents(event *events, long size);
long searchByTime(event *events, time_t t, long size);
long getFreeIndex(event *events, long size);

void readFromFile(const char *restrict fn, event *events, long count);
void readRecordFromfile(event *events, long index, FILE *fp);
int writeToFile(const char *restrict fn, event *events, long size);
long readFileAndCount(const char *restrict fn);

int writeFileHeader(FILE *fp);
int checkFileHeader(FILE *fp);