#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#define MAX 100
int i,j;
struct stack{
 int top;
 char stack[MAX];
}s;

int isEmpty()//Underflow condition
{
 if(s.top==-1)
  return 1;
 else
  return 0;
}

int isFull()//Overflow condition
{
 if(s.top==MAX-1)
  return 1;
 else
  return 0;
}

void push(char item)//PUSHING
{
  if(isFull())
  printf("Stack Overflow\n");
  else
  s.stack[++s.top]=item;
}

char pop()//Popping
{
 char a;
 if(isEmpty())
  printf("Stack Underflow\n");
 else
  return s.stack[s.top--];
}
void peep()//Check top of the stack
{
 int i;
 if(s.top==-1)
  printf("Top element is Empty nothing to peep at :)\n");
 else
  return s.stack[s.top];
}
int precedence(char a,char b)
{
 char arr[5];int a1,b1;
 arr[0]='+';arr[1]='-';arr[2]='*';arr[3]='/';arr[5]='^';
 for(i=0;i<4;i++)
 {
  if(a==arr[i])
   a1=i;
  if(b==arr[i])
   b1=i;
 }
 if(a1==b1)
  return 1;
 //if((a1==0 && b1==1) ||(a1==1 && b1=0) ||(a1==2 && b1==3) ||(a1==3 && b1==2))
 /*if((a1%2==0 && b1%2==0)
  return 1;
 if((a1%3==1 && b1%2==0)*/
   // return 1;
 else if(b1>a1)
  return 0;
}
int Alphanum(char a)//CHECKS if ALPHANUMERIC
{
 if(a!='(' && a!=')' && a!='{' && a!='}' && a!='[' && a!=']' && a!='+' &&
  a!='-' && a!='*' && a!='/' && a!='*')
  return 1;
 else
  return 0;
}
int convertInfixtoPostfix(char expr[])
{
 char pexpr[MAX];
 int len=strlen(expr);
 j=-1;
 for(i=0;i<len;i++)
 {
  if(isAlphanum(expr[i])==0)
     pexpr[++j]=expr[i];//Adds Alphanumeric directly to the pexpr
  else if(expr[i]=='('||expr[i]=='{'||expr[i]=='[')
  push(expr[i]);//Pushes opening brackets on the stack

  else if(expr[i]==')'||expr[i]=='}'||expr[i]==']')//CLOSING BRACKETS
  {
   if(expr[i]==')')//checks if top is ( if not then keep popping
   {
    while(!isEmpty() && peep()!='(')//keep popping and adding to pexpr till
           pexpr[++j]=pop();
    pop();// opening ( is found then pop that and dont add to pexpr
   }
   if(expr[i]=='}')
   {
    while(!isEmpty() && peep()!='{')
           pexpr[++j]=pop();
    pop();
   }
   if(expr[i]==']')
   {
    while(!isEmpty() && peep()!='[')
           pexpr[++j]=pop();
    pop();
   }
  }
  else{//For pushing and popping operators
   while(!isEmpty() && precedence(expr[i],peep())==0)
    pexpr[++j]=pop();//if peep precedence is higher then

   push(expr[i]);//if equal precedence then add to stack
  }
 }

 while(!isEmpty())
  pexpr[++j]=pop();

 printf("Infix expression : %s\n",expr);
 printf("Postfix expression : %s\n",pexpr);
}
void main()
{
 char expr[MAX];
 printf("Input a balanced infix expression\n");
 scanf("%s",expr);
 convertInfixtoPostfix(expr);
}

