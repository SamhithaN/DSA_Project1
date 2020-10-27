#include "dll.h"

NODE* insert_d(NODE *first)//rear
{
    NODE *elem=getnode();
    data(elem);

    if(first==NULL)
    {
        return elem;
    }
    else if(first->llink==NULL)
    {
        first->llink=elem;
        elem->rlink=first;
        return first;
    }
    else
    {
        NODE *cur,*prev;
        cur = first;
        prev=NULL;
        while(cur!=NULL)
        {
            prev=cur;
            cur=cur->llink;
        }
        prev->llink=elem;
        elem->rlink=prev;
        return first;
    }
}

NODE* delete_d(NODE *first)
{
    NODE *next,*prev=NULL;
    char key[10];
    if(first==NULL)
    {
        printf("DLL is empty");
        return NULL;
    }
    printf("Enter usn to be deleted");
    scanf(" %s",key);
    if(!(strcmp(first->usn,key)))
    {
        printf("Deleted node is %s",first->usn);

        next=first->llink;
        if(next!=NULL)
            next->rlink=NULL;
        free(first);
        return next;
    }

    NODE *cur=first;
    while(cur!=NULL)
    {
        if(!(strcmp(cur->usn,key)))
        {
            next=cur->llink;

            if(next!=NULL)
                next->rlink=prev;

            prev->llink=next;
            printf("Deleted node is %s",cur->usn);
            free(cur);
            return first;
        }
        prev=cur;
        cur=cur->llink;
    }

    printf("Student is not present in this list");
}

void dll()
{
    int ch;
    NODE *firstd=NULL;
    while(1)
    {
        printf("\n\nDLL:Enter choice\n1-Make list\n2-Delete\n3-Modify\n4-Display\n5-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case enter_student_data:
            firstd=insert_d(firstd);
            printf("The student has been added to the list");
            break;
        case delete_l:
            firstd=delete_d(firstd);
            break;
        case modify_l:
            firstd= modify_s(firstd);
            break;
        case display_l:
            display_s(firstd);
            break;
        default: return;
        }
    }
}
