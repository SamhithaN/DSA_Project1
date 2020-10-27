#ifndef BST_H
#define BST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<common.h>

void bst();
void traversal(NODE* root);
void display_bst_ele(NODE* rootelem);
void preorder(NODE* root);
void inorder(NODE* root);
void postorder(NODE* root);
NODE* insert_BST(NODE* root);
NODE* delete_BST(NODE* root);
NODE* modify(NODE *root);

#endif // BST_H
