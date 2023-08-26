#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node*next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *delete_end(struct node *);


int main(int argc,char *arg[])
{
	int ch;
	
do
{	printf("Enter choice\n");
	printf("1. Create a List\n");
	printf("2. Display a List\n");
	printf("3. Insert beg\n");
	printf("4. Delete end\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:start=create_ll(start);
				break;
		case 2:start=display(start);
				break;
		case 3:start=insert_beg(start);
				break;
		case 4:start=delete_end(start);
				break;		
		case 5: exit(0);
		default : printf("Invalid Choice");
				break;
			}
}while(ch!=5);
return 0;
}

struct node *create_ll(struct node *start)
{
	struct node *newnode, *ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter data\n");
	scanf("%d",&num);
	
	while(num!=-1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			
			ptr->next=newnode;
			newnode->next=NULL;
		}
		printf("Enter data\n");
		scanf("%d",&num);
	}
	return start;
}
		
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *newnode;int num;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&num);
	newnode->data=num;
	newnode->next=start;
	start=newnode;
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{	
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	
	return start;
}






		
	
