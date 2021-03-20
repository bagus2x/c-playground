#include <stdio.h>
#include <stdlib.h>
#include "singly_linkedlist.h"

#define TRUE 1

int main()
{
    LinkedList *list = llinit();
    int value;
    while (TRUE)
    {
        system("clear");
        printf("\n\n\nLINKED LIST\n");
        printf("1. Add data\n");
        printf("2. Remove node by index\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("1-4? .... ");

        scanf("%d", &value);
        printf("\n");

        switch (value)
        {
        case 1:
        {
            int data;
            printf("data (int): ? ");
            scanf("%d", &data);
            llinit(list, data);
        }
        break;
        case 2:
        {
            int index;
            printf("index (int): ? ");
            scanf("%d", &index);
            llremove(list, index);
        }
        break;
        case 3:
            llprint(list);
            printf("\n");
            char prompt;
            printf("Continue? (Y/n)\n");
            scanf(" %c", &prompt);
            if(prompt == 'Y' || prompt == 'y')
                continue;
            else
                return 0;
            break;
        default:
            return 0;
        }
    }
    return 0;
}