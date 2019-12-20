#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "read.h"
#include "event.h"

bool matches(char *str1, char *str2, int len);
void actOnCommand(char *command, event *events, int size);
void writeMenu();

void onAddEvent(event *events);
void onEditEvent(event *events);
void onDeleteEvent(event *events);

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

void onAddEvent(event *events)
{
    int hour;
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
    char *msg = "Adding Event...";
    char *msg2 = "Event was added.";
    editEvent(events, hour, msg, msg2);
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
    char *msg = "Editing Event...";
    char *msg2 = "Event was edited.";
    editEvent(events, hour, msg, msg2);
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