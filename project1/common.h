#ifndef COMMON_H
#define COMMON_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char *usn,*name,*dept,*phno;
    int *sem;
    struct student *llink,*rlink;
}NODE;

NODE* getnode();
void data(NODE* temp);
enum linkedlist{enter_student_data=1,delete_l,modify_l,display_l};

#endif // COMMON_H
