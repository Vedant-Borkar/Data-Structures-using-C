#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
 int data;
 struct node *next;
};
struct node *start=NULL;
struct node *insert_beg(struct node *start);
struct node *create_ll(struct node *start)
{
 struct node *newnode,*ptr;//Creating new node
 int num;//Ini. num to be inputed
 printf("Enter -1 to End\n");//To exit input Null
 printf("Enter the data:");//Input number
 scanf("%d",&num);
 while(num!=-1)
 {
  newnode = (struct node*)malloc(sizeof(struct node*));
  //Create a newnode of type struct* that has memoryalloc equal to the size of the node required

  newnode->data=num;//Stores num in the data part of the node
  if(start==NULL)//this block only executes once at the start of creation on LL
  {
   newnode->next=NULL;//Start points to 2nd node and next part of 2nd node points to NULL
   start=newnode;
  }
  else
  {//block executes each time a newnode is created until USER INPUTS -1
   ptr=start;//stores start in ptr as it is a temp variable
   while(ptr->next!=NULL)
    {ptr=ptr->next;}
   ptr->next=newnode;//
   newnode->next=NULL;//Start shifts ahead and each new node created becomes start, WE ADD AT THE BEGGINING HERE
  }

  printf("\nEnter Data: ");//Keep inputing data till user enter -1
  scanf("%d",&num);
 }
 return start;
}

struct node *display(struct node *start)//Display stored LL
{
  struct node *ptr;//create ptr variable of type struct node
  ptr=start;//Initi. ptr as start
  printf("\n");
  while(ptr!=NULL)//while ptr hasnt reached end
  {
   printf("\t%d",ptr->data);//prints the data part
   ptr=ptr->next;//ptr moves ahead to next node
  }
  return start;
}

int main()
{
 int choice=0;
 do
 {printf("\nEnter choice\n1.Create LL\n2.Display Stored LL\n3.Exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1: start=create_ll(start);
          break;
  case 2: start=display(start);
          break;
  case 3:exit(0);
          break;
  case 4: printf("Invalid Choice\n");
          break;
 }
 }while(choice!=3);
}



