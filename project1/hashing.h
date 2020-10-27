#ifndef HASHING_H
#define HASHING_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<common.h>

typedef struct hasht
{
    int K;
    long int L;
}ht;

int hash(int num,int hz);
int str_int(char str[]);
void insert(FILE *fp,ht h[],int hz);
void search(FILE *fp,ht h[],int hz);
void delete_hash(FILE *fp,ht h[],int hz);
void display(FILE *fp,ht h[],int hz);
void hashing();

#endif // HASHING_H
