#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void insert(int dat,struct node*head)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=dat;
	newnode->next=head;
	head=newnode;
}
void delete(int pos,struct node*head)
{
	int i;
	struct node*temp=head;
	if(head==NULL)
	{
		return;
	}
	if(pos==0)
	{
		head=temp->next;
		free(temp);
	}
	for(i=0 ; (temp!=NULL) && (i<pos) ;i++)
	{
		temp=temp->next;
	}
	if(temp==NULL || temp->next==NULL)
	{
		return;
	}
	struct node*next=temp->next->next;
	free(temp->next);
	temp->next=next;
}
void display(struct node*head)
{
	while(head!=NULL)
	{
		printf("%d \n",head->data);
		head=head->next;
	}
}
void main()
{
	struct node*head=NULL;
	int dat,c,i;
		insert(12,head);
		display(head);
		printf("hello");
		insert(13,&head);
		display(&head);
		insert(14,head);
		display(head);
}
