#include <stdio.h>
#include <stdlib.h>
#include "singly_linkedlist.h"

void llinsert(LinkedList *list, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (list->root == NULL)
    {
        list->root = temp;
        list->tail = temp;
    }
    else
    {
        list->tail->next = temp;
        list->tail = temp;
    }

    list->size += 1;
}

void llremove(LinkedList *list, int index)
{
    if (list == NULL || index > list->size)
        return;

    Node *current = list->root;

    if (index == 0)
    {
        Node *temp = current;
        list->root = current->next;
        free(temp);
        list->size -= 1;
        return;
    }

    for (int i = 0; i < list->size; i++)
    {
        if (i + 1 == index)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            if (index == list->size - 1)
                list->tail = current;
            list->size -= 1;
            break;
        }
        current = current->next;
    }
}

void llprint(LinkedList *list)
{
    if (list == NULL)
        return;

    Node *current = list->root;

    printf("[");
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;

        if (current != NULL)
            printf(", ");
    }
    printf("]\n");
}

int llpeak(LinkedList *list)
{
    return list->tail->data;
}

LinkedList *llinit()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->size = 0;
    return list;
}

LinkedList *llfree(LinkedList *list)
{
    Node *current = list->root;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return (LinkedList *)realloc(list, 0);
}