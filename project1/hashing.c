#include "hashing.h"

int hash(int num,int hz)
{
    return num%hz;
}

int str_int(char str[])
{
    int sum=0;
    for(int i=0;str[i]!='\0';i++)
    {
        sum+=str[i];
    }
    return sum;
}

void insert(FILE *fp,ht h[],int hz)
{
    int count,hval;
    struct student E1;

    printf("\n\nEnter the information of the student");
    printf("\nEnter USN\t");
    E1.usn=(char*)malloc(sizeof(char)*10);
    scanf("%s",E1.usn);
    printf("Enter name\t");
    E1.name=(char*)malloc(sizeof(char)*10);
    scanf("%s",E1.name);
    printf("Enter department\t");
    E1.dept=(char*)malloc(sizeof(char)*10);
    scanf("%s",E1.dept);
    printf("Enter semester\t");
    E1.sem=(int*)malloc(sizeof(int));
    scanf("%d",E1.sem);
    printf("Enter phone number\t");
    E1.phno=(char*)malloc(sizeof(char)*10);
    scanf("%s",E1.phno);
    E1.rlink=E1.llink=NULL;

    int numofstr = str_int(E1.usn);

    hval=hash(numofstr,hz);
    count=hval;
    while(h[hval].K!=-1)
    {
        hval=(hval+1)%hz;
        if(hval==count)
        {
            printf("Hash table is full\n");
            return;
        }
    }
    fseek(fp,0,SEEK_END);
    h[hval].L=ftell(fp);
    h[hval].K=numofstr;
    fwrite(&E1,sizeof(struct student),1,fp);

}

void search(FILE *fp,ht h[],int hz)
{
    int hval,count,numofstr;
    char key[10];
    struct student E1;

    printf("Enter the USN to be searched:");
    scanf(" %s",key);
    numofstr=str_int(key);

    hval=hash(numofstr,hz);
    count=hval;
    while(h[hval].K!=numofstr)
    {
        hval=(hval+1)%hz;
        if(hval==count)
        {
            printf("Unsuccessful search\n");
            return;
        }
    }
    fseek(fp,h[hval].L,SEEK_SET);
    fread(&E1,sizeof(struct student),1,fp);
    printf("\nInformation is\nName:%s\nUSN:%s\nDepartment:%s\nSem:%d\nPhoneNo:%s",E1.name,E1.usn,E1.dept,*E1.sem,E1.phno);
}

void delete_hash(FILE *fp,ht h[],int hz)
{
    int hval,count,numofstr;
    char key[10];

    printf("Enter the USN to be deleted:");
    scanf(" %s",key);
    numofstr=str_int(key);

    hval=hash(numofstr,hz);
    count=hval;
    while(h[hval].K!=numofstr)
    {
        hval=(hval+1)%hz;
        if(hval==count)
        {
            printf("Element is not present to delete\n");
            return;
        }
    }
    fseek(fp,h[hval].L,SEEK_SET);
    h[hval].K=-1;
    printf("Element has been deleted");
}

void display(FILE *fp,ht h[],int hz)
{
    int i;
    struct student E1;
    printf("Student information\n");
    for(i=0;i<hz;i++)
    {
        if(h[i].K!=-1)
        {
            fseek(fp,h[i].L,SEEK_SET);
            fread(&E1,sizeof(struct student),1,fp);
            printf("\nInformation is\nName:%s\nUSN:%s\nDepartment:%s\nSem:%d\nPhoneNo:%s",E1.name,E1.usn,E1.dept,*E1.sem,E1.phno);

        }
    }
}

enum hash{create=1,search_,delete_,display_};
void hashing()
{
    ht h[20];
    int hz=10,ch,i;
    FILE *fp;
    fp=fopen("Student.txt","w+");

    for(i=0;i<hz;i++)
    {
        h[i].K=-1;
    }

    while(1)
    {
        printf("\nEnter choice\n1-Insert\n2-Search\n3-Delete\n4-Display\n5-Return to Main Menu\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case create:
            insert(fp,h,hz);
            break;
        case search_:
            search(fp,h,hz);
            break;
        case delete_:
            delete_hash(fp,h,hz);
            break;
        case display_:
            display(fp,h,hz);
            break;
        default:return;
        }
    }
}

