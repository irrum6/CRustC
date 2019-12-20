#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "read.h"

struct _event
{
    int hour;
    char *name;
    char *description;
};

typedef struct _event event;
// typedef unsigned char BYTE;

bool matches(char *str1, char *str2, int len);

void writeMenu();

void initZero(event *events, int size);
void printEvents(event *events, int size);
void actOnCommand(char *command, event *events, int size);

void onAddEvent(event *events);
void onEditEvent(event *events);
void onDeleteEvent(event *events);
void addEvent(event *events, int hour, char *name, char *desc);
void editEvent(event *events, int hour, char *name, char *desc);
void deleteEvent(event *events, int hour);

int main(int argc, char **argv)
{
    const int DAYS = 30;
    const int HOURS = 24;
    const int TOTAL = HOURS; //DAYS * HOURS;

    event *events = malloc(TOTAL * sizeof(event));

    initZero(events, TOTAL);

    writeMenu();
    char command[7];
    bool notExit = true;
    while (!matches(command, "exit", 4))
    {
        int res = stdReadLine(3, 6, command);
        if (res < 0)
        {
            printf("short, type again\n");
            continue;
        }
        printf("%s\n", command);
        actOnCommand(command, events, TOTAL);
    }
    free(events); //out of loop free pointer
    return 0;
}

bool matches(char *str1, char *str2, int len)
{
    if (len < 0)
        return false;
    return (strncmp(str1, str2, len) == 0);
}
void actOnCommand(char *command, event *events, int size)
{
    if (matches(command, "help", 4))
    {
        writeMenu();
    }
    if (matches(command, "add", 3))
    {
        onAddEvent(events);
    }
    if (matches(command, "edit", 4))
    {
        onEditEvent(events);
    }
    if (matches(command, "list", 4))
    {
        printEvents(events, size);
    }
    if (matches(command, "delete", 6))
    {
        onDeleteEvent(events);
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
}
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
void addEvent(event *events, int hour, char *name, char *desc)
{
    printf("adding event...\n");
    events[hour].name = name;
    events[hour].description = desc;
    events[hour].hour = hour;
    printf("Event was added...\n");
}

void editEvent(event *events, int hour, char *name, char *desc)
{
    printf("editing event...\n");
    events[hour].name = name;
    events[hour].description = desc;
    events[hour].hour = hour;
    printf("Event was edited...\n");
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

void onAddEvent(event *events)
{
    int hour;
    char *name = malloc(sizeof(char) * 36);
    char *desc = malloc(sizeof(char) * 36);
    printf("type hour\n");
    scanf("%d", &hour);
    if (hour > 23 || hour < 0)
    {
        printf("not valid hour\n");
        return;
    }
    if (events[hour].hour != -1)
    {
        printf("Event is on calendar. You want to edit?\n");
        return;
    }
    getchar(); //discard enter
    printf("type name\n");
    stdReadLine(3, 36, name);
    printf("type description\n");
    stdReadLine(3, 36, desc);
    addEvent(events, hour, name, desc);
}
void onEditEvent(event *events)
{
    int hour;
    printf("type hour\n");
    scanf("%d", &hour);
    if (hour > 23 || hour < 0)
    {
        printf("not valid hour\n");
        return;
    }
    getchar(); //discard enter
    char *name = malloc(sizeof(char) * 36);
    char *desc = malloc(sizeof(char) * 36);
    printf("type name\n");
    stdReadLine(3, 36, name);
    printf("type description\n");
    stdReadLine(3, 36, desc);
    editEvent(events, hour, name, desc);
}
void onDeleteEvent(event *events)
{
    int hour;
    printf("type hour\n");
    scanf("%d", &hour);
    if (hour > 23 || hour < 0)
    {
        printf("not valid hour\n");
        return;
    }
    deleteEvent(events, hour);
}