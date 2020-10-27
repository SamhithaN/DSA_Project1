#include "bst.h"

NODE* insert_BST(NODE* root)
{
    NODE *ele=getnode();
    data(ele);

    if(root==NULL)
        return ele;
+
    NODE *cur,*prev;
    cur=root;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        if((strcmp(cur->usn,ele->usn))>0)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if((strcmp(prev->usn,ele->usn))<0)
        prev->rlink=ele;
    else
        prev->llink=ele;
    return root;
}

NODE* delete_BST(NODE* root)
{
    NODE *cur,*parent,*succ,*next;
    char key[10];

    if(root==NULL)
    {
        printf("BST is empty");
        return NULL;
    }

    printf("Enter element to be deleted");
    scanf(" %s",key);

    parent = NULL;
    cur=root;

    while(cur!=NULL)
    {

        if(!(strcmp(cur->usn,key)))
            break;

        parent=cur;
        if((strcmp(cur->usn,key))<0)
            cur=cur->rlink;
        else
            cur=cur->llink;
    }

    if(cur==NULL)
    {
        printf("Element does not exist");
        return root;
    }

    if(cur->llink==NULL)
        next=cur->rlink;
    else if(cur->rlink==NULL)
        next=cur->llink;
    else
    {
        //To find inorder succession
        succ=cur->rlink;
        while(succ->llink!=NULL)
            succ=succ->llink;
        succ->llink=cur->llink;
        next=cur->rlink;
    }
    if(parent==NULL)
    {
        free(cur);
        printf("Deletion successful");
        return next;
    }
    else
    {
        if(cur==parent->llink)
            parent->llink=next;
        else
            parent->rlink=next;
        free(cur);
        printf("Deletion successful");
        return root;
    }
}

NODE* modify(NODE *root)
{
    NODE* cur;
    char key[10];

    if(root==NULL)
    {
        printf("BST is empty");
        return NULL;
    }

    printf("Enter key element");
    scanf(" %s",key);
    cur=root;
    while(cur!=NULL)
    {
        if(strcmp(cur->usn,key)==0)
        {
            data(cur);
            return root;
        }
        else if(strcmp(cur->usn,key)>0)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    printf("Student not present in tree");
    return root;
}

void display_bst_ele(NODE* rootelem)
{
    printf("\nInformation is\nName:%s\nUSN:%s\nDepartment:%s\nSem:%d\nPhoneNo:%s",rootelem->usn,rootelem->name,rootelem->dept,*rootelem->sem,rootelem->phno);

}

void preorder(NODE* root)
{
    if(root==NULL)
        return;

    display_bst_ele(root);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(NODE* root)
{
    if(root==NULL)
        return;

    inorder(root->llink);
    display_bst_ele(root);
    inorder(root->rlink);
}
void postorder(NODE* root)
{
    if(root==NULL)
        return;

    postorder(root->llink);
    postorder(root->rlink);
    display_bst_ele(root);
}
enum traversing{preorder_=1,inorder_,postorder_};
void traversal(NODE* root)
{
    int ch;
    while(1)
    {
        printf("\n1-Preorder\n2-Inorder\n3-Postorder\n4-Return to BST Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case preorder_:
            preorder(root);
            break;
        case inorder_:
            inorder(root);
            break;
        case postorder_:
            postorder(root);
            break;
        default: return;
        }
    }
}
enum bst{create=1,delete_,modify_,traversal_};

void bst()
{
    NODE *root=NULL;
    int ch;

    while(1)
    {
        printf("\nBST:Enter choice\n1-Create BST\n2-Delete element\n3-Modify an element\n4-Traversal\n5-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case create:
            root=insert_BST(root);
            printf("BST element is created");
            break;
        case delete_:
            root=delete_BST(root);
            break;
        case modify_:
            root=modify(root);
            break;
        case traversal_:
            traversal(root);
            break;
        default:return;
        }
    }
}

