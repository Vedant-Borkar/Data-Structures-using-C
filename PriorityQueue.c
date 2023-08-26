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
void Enqueue()//COMPLEX Enqueue
{
 int val;
 if(isFull())
  printf("Queue is Full\n");
 else if(q.front==-1 && q.rear==-1)
  front=0;rear=0;
 else{
   int i=q.front,posn=q.front,temp=0,temp1,j;
   for(i=q.front;i<=q.rear;i++)
   {
    if(q.queue[i]>val){
      posn=i;temp=q.queue[i];
    q.queue[i]=val;
    break;
    }
   }
   if(posn>front)
   {
    for(j=posn+1;(j<=q.rear+1);j++)
    {
     temp1=q.queue[j]
    }
   }

 }
}
void Dequeue()//Simple Dequeue
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

