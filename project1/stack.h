#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<common.h>
#include<sll.h>

void stack();
NODE* insert_t(NODE* first);
NODE* delete_t(NODE* first);

enum stack_queue{insert_=1,delete_,display_};

#endif // STACK_H
