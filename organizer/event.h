struct _event
{
    int hour;
    char *name;
    char *description;
};

typedef struct _event event;


void initZero(event *events, int size);
void printEvents(event *events, int size);

void editEvent(event *events, int hour, char *msg, char *msg2);
void deleteEvent(event *events, int hour);