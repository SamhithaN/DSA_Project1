#include<stdio.h>
#include<stdlib.h>

#include<sll.h>
#include<cll.h>
#include<dll.h>
#include<hll.h>
#include<stack.h>
#include<queue.h>
#include<bst.h>
#include<hashing.h>


enum datatype{singlell=1,circularll,headerll,doublell,stack_,queue_,bst_,hash_table};
int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter choice 1-SLL,2-CLL,3-HLL,4-DLL,5-Stack,6-Queue,7-BST,8-Hash Table,9-Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case singlell:
            sll();
            break;
        case circularll:
            cll();
            break;
        case headerll:
            hll();
            break;
        case doublell:
            dll();
            break;
        case stack_:
            stack();
            break;
        case queue_:
            queue();
            break;
        case bst_:
            bst();
            break;
        case hash_table:
            hashing();
            break;
        default:exit(0);
        }
    }
}




