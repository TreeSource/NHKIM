/* Maintains a part database (array version) */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
} inventory[MAX_PARTS];

int num_parts = 0; //number of parts currently stored.

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int compare(const void *p1, const void *p2);

/*
main: Prompts the user to enter an operation code, then calls
a function to perform the requested action. Repeats until the
user enters the command 'q'. Prints an error message if the
user enters an illegal code.
*/
int main (void)
{
    char code;

    for(;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); //skips to end of line.
        switch (code)
        {
        case 'i': insert(); break;
        case 's': search(); break;
        case 'u': update(); break;
        case 'p': print(); break;
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
int find_part(int number)
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
void insert (void)
{
    int part_number; double price;

    if (num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) 
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    printf("Enter price of part: ");
    scanf("%lf", &inventory[num_parts].price);
    num_parts++;
}

/*
search: Prompts the user to enter a part number, then look up
the part in database. If the part exists, prints the name and
quantity on hand; if not, print error message.
*/
void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: %.2lf", inventory[i].price);
    }
    else printf("Part not found\n");
}

/*
update: Prompts user to enter a part number. Prints an error 
message if the part does not exist; otherwise, prompts the user
to enter change in quantity on hand and updates the database.
*/

void update(void)
{
    char ch; int i, number, change; 

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(num_parts);
    if (i >= 0)
    {
        printf("Enter one of the options (p - change price, q - change quantity): ");
        ch = getchar();
        switch (ch)
        {
        case 'q':
            
            printf("Enter change in quantity on hand: ");
            scanf("%d", &change);
            inventory[i].on_hand += change;

            break;
        case 'p':
            printf("Enter the new price of part: ");
            scanf("%lf", &inventory[i].price);
            break;
        default:
            break;
        }
    }
    else printf("Part not found.\n");
}

/*
print: Print a listing of all parts in the database, showing
the part number, part name, and quantity on hand. Parts are 
printed in order in which they were entered into the databse.
*/
void print(void)
{
    int i;

    qsort(inventory, num_parts, sizeof(struct part), compare);

    printf("Part number     Part name        " 
    "Quantity       Price\n");
    for(i = 0; i < num_parts; ++i)
        printf("%7d         %-25s%6d%5.2lf\n", inventory[i].number,
        inventory[i].name, inventory[i].on_hand, inventory[i].price);
}

int compare(const void *p1, const void *p2)
{
    int n1 = ((struct part *)p1)->number;
    int n2 = ((struct part *)p2)->number;
    return n1 - n2;
}