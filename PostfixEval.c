#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>//used for getting length of char array
#define MAX 200
int i,j,len;
struct stack{
 int top;
 float stack[MAX];
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

void push(float item)//PUSHING
{
  if(isFull())
  printf("Stack Overflow\n");
  else
  s.stack[++s.top]=item;
}

float pop()//Popping
{
 float temp=-1;
 if(isEmpty())
  printf("Stack Underflow\n");
 else
 {
  temp=s.stack[s.top];
  s.top=s.top-1;
 }
  return temp;

}
void EvaluatePostfix(char expr[])
{
 float ans,val1,val2;
 len=strlen(expr);
 for(i=0;i<len;i++)
 {
  if(isdigit(expr[i]))
   push((float)(expr[i]-'0'));
  else{
   val1=pop();
   val2=pop();
   switch(expr[i])
   {

   case '+':
     ans=val1+val2;
     break;
   case '-':
     ans=val2-val1;
     break;
   case '*':
     ans=val1*val2;
     break;
   case '/':
     ans=val2/val1;
     break;
   case '%':
     ans=(int)val1%(int)val2;
     break;
   }
   push(ans);
  }

 }
 printf("%f",pop());
}
int main()
{
 char expr[100];
 printf("Enter a postfix expression:\n");
 scanf("%s",expr);
 EvaluatePostfix(expr);
 return 0;
}

