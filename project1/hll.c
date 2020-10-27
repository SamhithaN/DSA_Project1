#include "hll.h"

void insert_h(NODE *head)
{
    NODE *cur=head;
    NODE *elem=getnode();
    data(elem);

    while(cur->llink!=NULL)
    {
        cur=cur->llink;
    }
    cur->llink=elem;
}

void delete_h(NODE *head)
{
    NODE *cur=head->llink, *prev=head, *next;
    if(head->llink==NULL)
    {
        printf("HLL is empty");
        return;
    }

    char key[10];
    printf("Enter usn to be deleted");
    scanf(" %s",key);

    while(cur!=NULL)
    {
        if(!(strcmp(cur->usn,key)))
        {
            next = cur->llink;
            prev->llink = next;
            printf("Deleted node is %s",cur->usn);
            free(cur);
        }
        prev=cur;
        cur=cur->llink;
    }
}

void modify_h(NODE *head)
{
    NODE *cur=head->llink;
    char key[10];
    if(head->llink==NULL)
    {
        printf("HLL is empty");
    }
    printf("Enter key to be modified");
    scanf("%s",key);
    while(cur!=NULL)
    {
        if(!(strcmp(cur->usn,key)))
        {
            data(cur);
            return;
        }
        cur=cur->llink;
    }
    printf("Student is not present");
}

void display_h(NODE *head)
{
    NODE *cur;
    if(head->llink==NULL)
    {
        printf("HLL is empty");
        return;
    }

    for(cur=head->llink;cur!=NULL;cur=cur->llink)
    {
        printf("\nInformation is\nName:%s\nUSN:%s\nDepartment:%s\nSem:%d\nPhoneNo:%s",cur->usn,cur->name,cur->dept,*cur->sem,cur->phno);
    }
}

void hll()
{
    int ch;
    NODE *head=getnode();

    while(1)
    {
        printf("\n\nHLL:Enter choice\n1-Make list\n2-Delete\n3-Modify\n4-Display\n5-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case enter_student_data:
            insert_h(head);
            printf("The student has been added to the list");
            break;
        case delete_l:
            delete_h(head);
            break;
        case modify_l:
            modify_h(head);
            break;
        case display_l:
            display_h(head);
            break;
        default: return;
        }
    }
}
