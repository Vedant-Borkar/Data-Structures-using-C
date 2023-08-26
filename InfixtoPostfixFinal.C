#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
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
 char a,temp;
 if(isEmpty())
  printf("Stack Underflow\n");
 else
 {
  temp=s.stack[s.top];
  s.top=s.top-1;
  return temp;
 }
}
char peep()//Check top of the stack
{

  return s.stack[s.top];

}
int precedence(char ch)
{
 switch (ch)
 {
 case '+':
 case '-':
  return 1;
 case '*':
 case '/':
  return 2;
 case  '^':
  return 3;
 }
 return -1;
}
int Alphanum(char a)//CHECKS if ALPHANUMERIC
{
 if(a!='(' && a!=')' && a!='{' && a!='}' && a!='[' && a!=']' && a!='+' &&
  a!='-' && a!='*' && a!='/' && a!='*')
  return 1;
 else
  return 0;
}
void convertInfixtoPostfix(char expr[])
{
 char pexpr[MAX];
 int len=strlen(expr);
 j=-1;
 for(i=0;i<len;i++)
 {
  if(Alphanum(expr[i])==1)/**isalnum function from ctype.h is used to check if alphanum char**/
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
   while(!isEmpty() && precedence(expr[i])<=precedence(peep()))
    pexpr[++j]=pop();//if peep precedence is higher then

   push(expr[i]);//if equal precedence then add to stack
  }
 }

 while(!isEmpty())
  pexpr[++j]=pop();

 printf("  Infix expression : %s\n",expr);
 printf("Postfix expression : %s\n",pexpr);
}
int main()
{
 char expr[MAX];
 printf("Input a balanced infix expression\n");
 scanf("%s",expr);
 convertInfixtoPostfix(expr);
 return 0;
}

