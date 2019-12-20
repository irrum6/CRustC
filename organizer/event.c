#include <stdio.h>
#include <stdlib.h>

#include "read.h"
#include "event.h"

void printEvents(event *events, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Event %d\n", i);
        printf("Hour:%d\n", events[i].hour);
        printf("Name:%s\n", events[i].name);
        printf("Description:%s\n", events[i].description);
    }
}
void initZero(event *events, int size)
{
    for (int i = 0; i < size; i++)
    {
        events[i].hour = -1;
        events[i].description = NULL;
        events[i].name = NULL;
    }
}

void editEvent(event *events, int hour, char *msg, char *msg2)
{
    printf("%s\n", msg);
    char *name = malloc(sizeof(char) * 36);
    char *desc = malloc(sizeof(char) * 36);
    printf("type name\n");
    stdReadLine(3, 36, name);
    printf("type description\n");
    stdReadLine(3, 36, desc);
    events[hour].name = name;
    events[hour].description = desc;
    events[hour].hour = hour;
    printf("%s\n", msg2);
}

void deleteEvent(event *events, int hour)
{
    printf("deleting event...\n");
    if (hour > 23 || hour < 0)
    {
        printf("not valid hour\n");
        return;
    }
    events[hour].name = NULL;
    events[hour].description = NULL;
    events[hour].hour = -1;
    printf("Event was deleted...\n");
}