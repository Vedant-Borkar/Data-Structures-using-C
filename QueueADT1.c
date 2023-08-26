#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
 int front,rear;
 int queue[MAX-1];
}q;

int isEmpty()
{
 if(q.front==-1 && q.rear==-1)
  return 1;
 else
  return 0;
}

int isFull()
{
 if(q.rear==MAX-1)
  return 1;
 else
  return 0;
}
void Enqueue()
{
 int num;
 if(isFull())
 printf("Queue is full\n");

 else
 {
  printf("Enter number to be inserted\n");
  scanf("%d",&num);
  if(isEmpty())
  {
   ++q.front;++q.rear;
   q.queue[q.rear]=num;
  }
  else
   q.queue[++q.rear]=num;
 }
}
void Dequeue()
{
 int val;
 if(isEmpty())
  printf("Queue is empty\n");
 else
 {
  val=q.queue[q.front];
  if(q.front==q.rear)
   q.front=q.rear=-1;
  else
   q.front++;

   printf("%d is removed\n",val);
 }

}
void display()
{
 int i;
 if(isEmpty())
  printf("Queue is empty\n");
 else{
  for(i=q.front;i<=q.rear;i++)
  {
   printf("%d ",q.queue[i]);
  }
 }
 printf("\n");
}
void  main()
{
 int choice;
 q.front=-1,q.rear=-1;
 do
 {
  printf("--------------------------------\n");
  printf("   1.Enqueue    enter 1         \n");
  printf("   2.Dequeue    enter 2         \n");
  printf("   3.DISPLAY    enter 3         \n");
  printf("   4.EXIT       enter 4         \n");
  printf("    ENTER   CHOICE:        \n");
  printf("--------------------------------\n");
  scanf("%d",&choice);

  switch(choice)
  {
   case 1:Enqueue();
          break;
   case 2:Dequeue();
          break;
   case 3:display();
          break;
   case 4:exit(0);
          break;
   default : printf("INVALID CHOICE\n");
          break;
  }

 }while(choice!=4);
}
