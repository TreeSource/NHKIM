/* Maintains a part database (array version) Programming project 17_Q1~Q2 reallocation & qsort */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define INIT_MAX_PARTS 10

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int max_parts = 10;
int num_parts = 0; //number of parts currently stored.

int find_part(struct part *inventory, int number);
void insert(struct part *inventory);
void search(struct part *inventory);
void update(struct part *inventory);
void print(struct part *inventory);
int grow_array(struct part **array, int max);
int compare_parts(const void *a, const void *b);

/*
main: Prompts the user to enter an operation code, then calls
a function to perform the requested action. Repeats until the
user enters the command 'q'. Prints an error message if the
user enters an illegal code.
*/
int main (void)
{
    char code;
    struct part *inventory = malloc(INIT_MAX_PARTS * sizeof(struct part));

    for(;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); //skips to end of line.
        switch (code)
        {
        case 'i': insert(inventory); break;
        case 's': search(inventory); break;
        case 'u': update(inventory); break;
        case 'p': print(inventory); break;
        case 'q': return 0; break;
        
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

/*
find part: Looks up a part number in inventory array. Returns
the array index if the part number is found; otherwise, returns
-1.
*/
int find_part(struct part *inventory, int number)
{
    int i;
    for (i = 0; i < num_parts; ++i)
        if (inventory[i].number == number) return i;
    return -1;
}

/*
insert: Prompts the user for information about a new part and
then inserts the part into the database. Prints an error
message and returns prematurely if the part already exists or
the database is full.
*/
void insert (struct part *inventory)
{
    int part_number;

    if (num_parts == max_parts)
    {
        max_parts = grow_array((struct part **) &inventory, max_parts);
        if (!max_parts) {printf("There is no more room\n"); exit(1);}
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(inventory, part_number) >= 0) 
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

int grow_array(struct part **array, int max)
{
    max *= 2;
    struct part *temp = realloc(*array, max*sizeof(struct part));
    if (temp == NULL)
    {
        printf("cannot allocate more memory.\n");
        return 0;
    }
    else *array = temp;
    return max;
}

/*
search: Prompts the user to enter a part number, then look up
the part in database. If the part exists, prints the name and
quantity on hand; if not, print error message.
*/
void search(struct part *inventory)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, number);
    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else printf("Part not found\n");
}

/*
update: Prompts user to enter a part number. Prints an error 
message if the part does not exist; otherwise, prompts the user
to enter change in quantity on hand and updates the database.
*/

void update(struct part *inventory)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts);
    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else printf("Part not found.\n");
}

/*
print: Print a listing of all parts in the database, showing
the part number, part name, and quantity on hand. Parts are 
printed in order in which they were entered into the databse.
*/
void print(struct part *inventory)
{
    int i;

    qsort(inventory, num_parts, sizeof(struct part), compare_parts);

    printf("Part number     Part name           " 
    "Quantity on hand\n");
    for(i = 0; i < num_parts; ++i)
        printf("%7d         %-25s%11d\n", inventory[i].number,
        inventory[i].name, inventory[i].on_hand);
}

int compare_parts(const void *a, const void *b)
{
    const struct part *p = a, *q = b;
    return p->number - q->number;
}