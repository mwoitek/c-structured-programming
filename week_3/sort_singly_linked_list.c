/*
 *
 *
 * ██╗    ██╗ ██████╗ ██╗████████╗███████╗██╗  ██╗
 * ██║    ██║██╔═══██╗██║╚══██╔══╝██╔════╝██║ ██╔╝
 * ██║ █╗ ██║██║   ██║██║   ██║   █████╗  █████╔╝
 * ██║███╗██║██║   ██║██║   ██║   ██╔══╝  ██╔═██╗
 * ╚███╔███╔╝╚██████╔╝██║   ██║   ███████╗██║  ██╗
 *  ╚══╝╚══╝  ╚═════╝ ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
 *
 *
 *
 *  ______
 * /\  ___\
 * \ \ \____
 *  \ \_____\
 *   \/_____/
 *
 *
 *
 * C implementation of the BUBBLE SORT algorithm. This version of the algorithm
 * is for sorting a SINGLY LINKED LIST.
 *
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MAX_RAND_INT - 1 is the largest integer that will be randomly generated. */
#define MAX_RAND_INT 101

/* Definition of a singly linked list. */
typedef struct list
{
    int entry;
    struct list *next;
}
list;

/* This function creates a singly linked list with one entry. */
list* create_list(int num)
{
    list* head = malloc(sizeof(list));

    head->entry = num;
    head->next = NULL;
    return head;
}

/* This function adds an entry to a singly linked list. The new entry is at the
   beginning of the list. */
list* add_to_front(int num, list* hd)
{
    list* head = create_list(num);

    head->next = hd;
    return head;
}

/* This function creates a singly linked list with N randomly generated
   integers. For this assignment, we need to set N = 100. */
list* create_random_list(unsigned int N)
{
    list* head = create_list(rand() % MAX_RAND_INT);
    unsigned int i;

    for (i = 1; i < N; i++) {
        head = add_to_front(rand() % MAX_RAND_INT, head);
    }
    return head;
}

/* This function prints a singly linked list with N entries. We print rows with
   5 entries each. Then we assume N is a non-zero multiple of 5. */
void print_list(list* hd)
{
    unsigned int i;
    char row[100];
    char str_entry[20];

    while (hd != NULL) {
        strcpy(row, "");
        for (i = 0; i < 5; i++) {
            sprintf(str_entry, "%d\t", hd->entry);
            strcat(row, str_entry);
            hd = hd->next;
        }
        printf("%s\n", row);
    }
    return;
}

/* This function is for swapping two entries of a singly linked list. */
void swap(list* hd1, list* hd2)
{
    int temp = hd1->entry;

    hd1->entry = hd2->entry;
    hd2->entry = temp;
    return;
}

/* This function sorts a singly linked list by using the bubble sort algorithm. */
void bubble_sort(list* hd)
{
    list* hd1;
    list* hd2 = NULL;
    int swapped;

    do {
        hd1 = hd;
        swapped = 0;
        while (hd1->next != hd2) {
            if (hd1->entry > hd1->next->entry) {
                swap(hd1, hd1->next);
                swapped = 1;
            }
            hd1 = hd1->next;
        }
        hd2 = hd1;
    } while (swapped == 1);
    return;
}

int main()
{

    list* head;
    unsigned int N;
    int temp;

    printf("Sorting a SINGLY LINKED LIST with BUBBLE SORT\n\n");
    printf("The length N of the list can be any strictly positive "
           "multiple of 5.\n");
    printf("Enter the value of N: ");
    if (scanf("%d", &temp) != 1) {
        printf("Your input isn't an integer!\n");
        return -1;
    }
    if ((temp % 5 != 0) || (temp <= 0)) {
        printf("This value is not allowed!\n");
        return -1;
    }
    N = (unsigned int) temp;

    /* Creates a singly linked list with N randomly generated integers. */
    head = create_random_list(N);

    printf("\nThis is the ORIGINAL LIST:\n");
    print_list(head);

    bubble_sort(head);
    printf("\nThis is the SORTED LIST:\n");
    print_list(head);

    return 0;

}
