#include "stack.h"

NODE* insert_t(NODE* first)
{
    NODE *elem=getnode();
    data(elem);

    if(first==NULL)
        return elem;
    elem->llink=first;
    return elem;
}

NODE* delete_t(NODE* first)
{
    NODE* next;
    if(first==NULL)
    {
        printf("List is empty");
        return NULL;
    }
    else if(first->llink==NULL)
    {
        printf("Deleted usn is %s",first->usn);
        free(first);
        return NULL;
    }
    else
    {
        next = first->llink;
        printf("Deleted usn is %s",first->usn);
        free(first);
        return next;
    }
}

void stack()
{
    int ch;
    NODE *top=NULL;
    while(1)
    {
        printf("\nEnter choice\n1-Push\n2-Pop\n3-Display\n4-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case insert_:
            top=insert_t(top);
            break;
        case delete_:
            top=delete_t(top);
            break;
        case display_:
            display_s(top);
            break;
        default:return;
        }
    }
}

