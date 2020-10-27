#include "common.h"

NODE* getnode()
{
    NODE* temp;
    temp = (NODE*)malloc(sizeof(struct student));
    if(temp==NULL)
    {
        printf("Memory does not exist");
        exit(0);
    }
    return temp;
}

void data(NODE* temp)
{
    printf("\n\nEnter the information of the student");
    printf("\nEnter USN\t");
    temp->usn=(char*)malloc(sizeof(char)*10);
    scanf("%s",temp->usn);
    printf("Enter name\t");
    temp->name=(char*)malloc(sizeof(char)*10);
    scanf("%s",temp->name);
    printf("Enter department\t");
    temp->dept=(char*)malloc(sizeof(char)*10);
    scanf("%s",temp->dept);
    printf("Enter semester\t");
    temp->sem=(int*)malloc(sizeof(int));
    scanf("%d",temp->sem);
    printf("Enter phone number\t");
    temp->phno=(char*)malloc(sizeof(char)*10);
    scanf("%s",temp->phno);
    temp->rlink=temp->llink=NULL;
}

