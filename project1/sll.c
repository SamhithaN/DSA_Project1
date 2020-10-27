#include "sll.h"

NODE* insert_s(NODE* first)//rear
{
    NODE *elem=getnode();
    data(elem);

    if(first==NULL)
    {
        //elem->llink=NULL;
        return elem;
    }

    else if(first->llink==NULL)
    {
        first->llink = elem;
        //elem->llink=NULL;
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
        prev->llink = elem;
        //elem->llink=NULL;
        return first;
    }
}

NODE* delete_s(NODE* first)
{
    NODE *next,*prev=NULL;
    char key[10];

    if(first==NULL)
    {
        printf("SLL is empty");
        return NULL;
    }

    printf("Enter usn to be deleted");
    scanf(" %s",key);
    if(!(strcmp(first->usn,key)))
    {
        printf("Deleted node is %s",first->usn);
        next=first->llink;
        free(first);
        return next;
    }

    NODE *cur=first->llink;
    prev=first;
    while(cur!=NULL)
    {
        if(!(strcmp(cur->usn,key)))
        {
            next = cur->llink;
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

NODE* modify_s(NODE* first)
{
    NODE *cur=first;
    char key[10];

    if(first==NULL)
    {
        printf("SLL is empty");
        return NULL;
    }

    printf("Enter key to be modified");
    scanf("%s",key);
    while(cur!=NULL)
    {
        if(!(strcmp(cur->usn,key)))
        {
            data(cur);
            return first;
        }
        cur=cur->llink;
    }
    printf("Student is not present");
}

void display_s(NODE* first)
{
    int count=0;

    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    while(first!=NULL)
    {
        printf("\nInformation is\nUSN:%s\nName:%s\nDepartment:%s\nSem:%d\nPhoneNo:%s",first->usn,first->name,first->dept,*first->sem,first->phno);
        count++;
        first=first->llink;
        printf("\n");
    }
    printf("The number of students is %d",count);
}

void sll()
{
    int ch;
    NODE* first=NULL;
    while(1)
    {
        printf("\n\nSLL:Enter choice\n1-Enter student data\n2-Delete\n3-Modify\n4-Display\n5-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case enter_student_data:
            first=insert_s(first);
            printf("\nThe element has been added to the list");
            break;
        case delete_l:
            first=delete_s(first);
            break;
        case modify_l:
            first= modify_s(first);
            break;
        case display_l:
            display_s(first);
            break;
        default: return;
        }
    }
}
