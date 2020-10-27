#include "cll.h"

NODE* insert_c(NODE* last)//rear
{
    NODE *prev,*first;

    NODE *elem=getnode();
    data(elem);

    if(last==NULL)
    {
        elem->llink=elem;
        return elem;
    }
    else
    {
        first=last->llink;
        prev=last;
        prev->llink=elem;
        elem->llink=first;
        return elem;
    }
}

NODE* delete_c(NODE *last)
{
    NODE *cur,*prev=NULL;
    char key[10];
    if(last==NULL)
    {
        printf("\nCLL is empty\n");
        return NULL;
    }

    printf("Enter usn to be deleted");
    scanf("%s",key);
    if(last->llink==last)
    {
        if(strcmp(last->usn,key))
        {
            printf("Student is not present in this list");
            return last;
        }
        free(last);
        return NULL;
    }

    cur=last;
    while(cur->llink!=last)
    {
        prev=cur;
        cur=cur->llink;
        if(!(strcmp(cur->usn,key)))
        {
            if(cur==last->llink)
                last->llink=cur->llink;
            else
                prev->llink=cur->llink;
            free(cur);
            return last;
        }
    }

    if(!(strcmp(last->usn,key)))
    {
        cur->llink=last->llink;
        free(last);
        return cur;
    }
    printf("Student is not present in this list");
}

NODE* modify_c(NODE* last)
{
    NODE *cur=last->llink;
    char key[10];

    if(last==NULL)
    {
        printf("\nCLL is empty\n");
        return NULL;
    }

    printf("Enter key to be modified");
    scanf("%s",key);
    do
    {
        if(!(strcmp(cur->usn,key)))
            break;
        cur=cur->llink;
    }while(cur!=last->llink);
    data(cur);
    return last;
}

void display_c(NODE *last)
{
    NODE *first;
    if(last==NULL)
        printf("\nCLL is list\n");
    else
    {
        first=last->llink;
        do
        {
            printf("\nInformation is\nName:%s\nUSN:%s\nDepartment:%s\nSem:%d\nPhoneNo:%s",first->usn,first->name,first->dept,*first->sem,first->phno);
            first=first->llink;
        }while(first!=last->llink);
    }
}

void cll()
{
    int ch;
    NODE *last=NULL;
    while(1)
    {
        printf("\n\nCLL:Enter choice\n1-Enter student data\n2-Delete\n3-Modify\n4-Display\n5-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case enter_student_data:
            last=insert_c(last);
            printf("\nThe element has been added to the list");
            break;
        case delete_l:
            last=delete_c(last);
            break;
        case modify_l:
            last= modify_c(last);
            break;
        case display_l:
            display_c(last);
            break;
        default: return;
        }
    }
}

