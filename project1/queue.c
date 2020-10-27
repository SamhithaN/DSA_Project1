#include "queue.h"

void queue()
{
    int ch;
    NODE *first=NULL;
    while(1)
    {
        printf("\nEnter choice\n1-Insert\n2-Delete\n3-Display\n4-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case insert_:
            first=insert_s(first);
            break;
        case delete_:
            first=delete_t(first);
            break;
        case display_:
            display_s(first);
            break;
        default:return;
        }
    }
}

