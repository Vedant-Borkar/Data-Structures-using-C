#include<stdio.h>
#define MAX 5
struct stack
{
 int top;
 int stack[MAX];
}s;

void push()
{
 int num;
 if(s.top==MAX-1)
  printf("Stack Overflow\n");
 else
 {
  s.top=s.top+1;
  printf("Enter number to be inserted in the stack\n");
  scanf("%d",&num);
  s.stack[s.top]=num;
 }

}
void pop()
{
 if(s.top==-1)
  printf("Stack Underflow\n");
 else
 {
  printf("Number removed from the stack is %d \n",s.stack[s.top]);
  s.top=s.top-1;
 }


}
void display()
{
 int i;
 if(s.top==-1)
  printf("Stack is Empty nothing to Display\n");
 else
 {
  for(i=s.top;i>=0;i--)
  {
   printf("%d ",s.stack[i]);
  }
  printf("\n");
 }

}
void main()
{
 int choice;s.top=-1;
 do
 {
  printf("--------------------------------\n");
  printf("   1.PUSH    enter 1         \n");
  printf("   2.POP     enter 2         \n");
  printf("   3.DISPLAY enter 3         \n");
  printf("   4.EXIT    enter 4         \n");
  printf("    ENTER   CHOICE:        \n");
  printf("--------------------------------\n");
  scanf("%d",&choice);

  switch(choice)
  {
   case 1:push();
          break;
   case 2:pop();
          break;
   case 3:display();
          break;
   case 4:break;
   default : printf("INVALID CHOICE\n");
          break;
  }

 }while(choice!=4);
}
