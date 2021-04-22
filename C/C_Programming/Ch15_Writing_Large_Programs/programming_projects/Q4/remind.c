// Programming project Ch15_Q4 from 13_5_remind.c
#include "read_line.h"
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 // maximum number of reminders.
#define MSG_LEN 60 // max length of reminder message.

int main (void)
{
    char reminders [MAX_REMIND][MSG_LEN + 3], day_str [3], msg_str [MSG_LEN + 1];
    int day, i, j, num_remind = 0;
    for (;;) 
    {
        if (num_remind == MAX_REMIND) {printf("-- No space left --"); break;}

        printf ("Enter day and reminder: ");
        scanf ("%2d", &day);
        if (day == 0) break;
        sprintf (day_str, "%2d", day);
        read_line (msg_str, MSG_LEN);

        for (i = 0; i < num_remind; ++i) if (strcmp(day_str, reminders[i]) < 0) break; // find the index to put reminder
        for (j = num_remind; j > i; --j) strcpy(reminders[j], reminders[j-1]); // push all other reminder into back to create space for present reminder

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; ++i) printf(" %s\n", reminders[i]);

    return 0;
}