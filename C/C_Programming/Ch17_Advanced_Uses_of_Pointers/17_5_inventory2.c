/* Maintains a parts database (linked list version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25

struct part
{
    int number, on_hand; char name[NAME_LEN + 1]; struct part *next;
};

struct part *inventory = NULL; /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int compare_parts(const void *p, const void *q);

/*
main: Prompts the user to enter an operation code, then calls a
function to perform the requested action. Repeats until the user
enters the command 'q'. Prints an error message if the user enters
an illegal code.
*/
int main(void)
{
    char code;
    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); /* skips to end of line */
        switch (code)
        {
        case 'i': insert(); break;
        case 's': search(); break;
        case 'p': print(); break;
        case 'q': return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

/*
find_part: Looks up a part number in the inventory list. Returns a
pointer to the node containing the part number; if the part number is
not found, returns NULL.
*/
struct part *find_part(int number)
{
    struct part *p;
    for (p = inventory; p != NULL && number > p->number; p = p->next);
    if (p != NULL && number == p->number) return p;
    return NULL;
}
/*
Prompts the user for information aobut a new part and then inserts the
part into the inventory list; the list remains sorted by part number.
Prints an error mesage and returns prematurely if the part already
exists or space could not be allocated for the part.
*/
void insert(void)
{
    struct part *cur, *prev, *new_node;
    if ((new_node = malloc(sizeof(struct part))) == NULL)
    {
        printf("Database is full;  can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next);
    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n"); free(new_node); return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL) inventory = new_node;
    else prev->next = new_node;
}

/*
search; Prompts the user to enter a part number, then looks up the 
part in the database. If the part exists, prints the name and quantity
on hand; if not, prints an error message.
*/
void search(void)
{
    int number; struct part *p;
    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) 
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else printf("Part not found\n");
}

/*
update: Prompts the user to enter a part number. Prints an error
message if the part doesn't exist; otherwise, prompts the user to
enter change in quantity on hand and updates the database.
*/
void update(void)
{
    int number, change; struct part *p;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    if (p = find_part(number)) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
    else printf("Part not found.\n");
}

/*
print: Prints a listing of all parts in the databse. showing the
part number, part name, and quantity on hand. Part numbers will
appear in ascending order.
*/
void print(void)
{
    struct part *p;

    printf("Part Number Part Name               " "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next) printf("%7d         %-25s%11d\n", p->number, p->name, p->on_hand);
    
}

int compare_parts(const void *p, const void *q)
{
    return ((const struct part *) q)->number - ((const struct part *) p)->number;
}

int compare_parts_name(const void *p, const void *q)
{
    return strcmp(((const struct part *)p)->name, ((const struct part *)q)->name);
}