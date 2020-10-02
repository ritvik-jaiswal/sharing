#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int id,sem;
    char name[10];
    struct node * right;
};
typedef struct node NODE;
NODE *head = NULL;
NODE *start=NULL;
NODE *temp2 = NULL;
NODE *temp1 = NULL;
NODE * getnode()
{
    NODE * x = (NODE *)malloc(sizeof(NODE));
    return x;
}
void insert()
{
    NODE * temp;
    temp = getnode();
    printf("Enter Student's name\n");
    scanf("%s",temp->name);
    printf("Enter id\n");
    scanf("%d",&temp->id);
    printf("Enter sem\n");
    scanf("%d",&temp->sem);
    temp->right=NULL;
    if(head==NULL)//insert 1st node
    {
        head=temp;
        start=head;
        return;
    }
    else if(strcmp(head->name,temp->name)>0)
    {
        temp->right=head;
        head=temp;
    }
    else
    {
        for(temp1!=NULL,temp2=head;temp2!=NULL && strcmp(temp->name,temp2->name)>0;temp2=temp2->right)
               temp1=temp2;
        temp1->right = temp;
        temp->right = temp2;
    }
    head=temp;
}
void delete()
{   head=start;
    char n[10];
    int flag=0;
    if(head==NULL)
    {
        printf("Empty\n");
        return;
    }
    printf("Enter student's name to be deleted\n");
    scanf("%s",n);
    if(strcmp(n,head->name)==0)
    {
        head=head->right;
        start=head;
        printf("Deleted!!\n");
        return;
    }
    for(temp1=NULL,temp2=head;temp2!=NULL;temp2=temp2->right)
      if(strcmp(n,temp2->name)==0)
      {
          flag=1;
          break;
      }
      else
      {
          temp1=temp2;
      }
     if(flag==0)
     printf("Students name not present\n");
     else
     {
         temp1->right=temp2->right;
         printf("student's data has been deleted\n");
         free(temp2);
     }
      return;
}
void show()
{
    NODE * s;
    s=start;
     printf("NAME          ID         SEM\n");

    if(s==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        
        while(s->right!=NULL)
        {
             printf("%s"           "%d      %d\n",s->name,s->id,s->sem);
             s=s->right;
        }      
        printf("%s"          "%d      %d\n",s->name,s->id,s->sem); 
    }
    
}
void main()
{
    int ch;
    while(1)
    {
        printf("1:enter details   2:show details      3:delete\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
              insert();
              break;
            case 2:
              show();
              break;
            case 3:
              delete();
              break;
            default:
              printf("Wrong choice\n");      
        }
    }
}
