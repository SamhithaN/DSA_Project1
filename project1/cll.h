#ifndef CLL_H
#define CLL_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<common.h>

void cll();
NODE* insert_c(NODE* last);
NODE* delete_c(NODE *last);
NODE* modify_c(NODE* last);
void display_c(NODE *last);

#endif // CLL_H
