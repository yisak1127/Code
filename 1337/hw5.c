// yisak worku yxw190038
#include "stdio.h"
#include <stdlib.h>

struct Node
{
    /* data */
    int num;
    struct Node *next;
};

void bubbleSort(struct Node *head)
{
    struct Node *cur = head;
    int swap = 1;
    while (swap == 1)
    {
        swap = 0;
        while (cur->next->next)
        {
            if (cur->num > cur->next->num)
            {
                swap = 1;
                int temp = cur->num;
                cur->num = cur->next->num;
                cur->next->num = temp;
            }
            cur = cur->next;
        }

        cur = head;
        for (int i = 0; i < 8; i++)
        {
            printf("%i ", cur->num);
            cur = cur->next;
        }
        printf("\n");
        cur = head;
    }
}

void selectionSort(struct Node *head)
{
    struct Node *cur = head;
    struct Node *temp = head;
    int small = 0;
    while (cur->next->next)
    {
        struct Node *smallest = cur;
        while (cur->next)
        {
            if (smallest->num > cur->num)
            {
                smallest = cur;
            }
            cur = cur->next;
        }
        cur = temp;
        small = smallest->num;
        smallest->num = cur->num;
        cur->num = small;

        cur = head;
        for (int i = 0; i < 8; i++)
        {
            printf("%i ", cur->num);
            cur = cur->next;
        }
        printf("\n");
        temp = temp->next;
        cur = temp;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *cur = head;
    struct Node *cur2 = head2;
    int x = 0;
    printf("8 input\n");

    for (int i = 0; i < 8; i++)
    {
        scanf("%i", &x);
        cur->num = x;
        cur2->num = x;
        cur->next = (struct Node *)malloc(sizeof(struct Node));
        cur2->next = (struct Node *)malloc(sizeof(struct Node));
        cur = cur->next;
        cur2 = cur2->next;
    }

    cur = head;
    cur2 = head2;

    for (int i = 0; i < 8; i++)
    {
        printf("%i ", cur->num);
        cur = cur->next;
    }
    printf("\n");

    bubbleSort(head);

    for (int i = 0; i < 8; i++)
    {
        printf("%i ", cur2->num);
        cur2 = cur2->next;
    }
    printf("\n");
    cur2 = head2;
    selectionSort(head2);
}