#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100
int flag=0;//we will have to check if static int is needed or not
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
void push(char item)
{

}
void pop()//Popping if matched pair
{
 char a;
 if(isEmpty())
  printf("Stack Underflow\n");
 else
 {
  s.top=s.top-1;
 }
}
void AlphaRemove(char exp[], int len)//Alphabet and number remover
{
 int i;
 for(i=0;i<len;i++)
 {
  if((exp[i]=='('||exp[i]==')'||exp[i]=='['||exp[i]==']'||exp[i]=='{'||exp[i]=='}'))
   {
    Balance(exp[i]);
   }
 }
 if(isEmpty())//Case 4:To check if After all operations if there is any open bracket left
  flag=flag+1;

}

int checkPair(char val1,char val2)//Pair matching or not condition checker
{
 return((val1=='('&&val2==')')||(val1=='['&& val2==']')||(val1=='{'&& val2=='}'));
}

int Balance(char a)//Balanced condition cases
{
 if((a=='('||a=='['||a=='{'))
     push(a);//Case 1:Push if opening bracket
 else{
  if(isEmpty())
   return flag=0;
  else if(checkPair(s.stack[s.top],a))
   pop();//Case 2: Pop if match
  else
   return flag=0;/*Case 3: opening not match and is done to skip
             //continue;//to skip the return 0 at the bottom */
 }
}

void main()
{
 s.top=-1;char exp[MAX];int i=0,len;
 printf("Enter a Mathematical Expression\n");
 scanf("%s",exp);
 len=strlen(exp);
 AlphaRemove(exp,len);
 //inside Balanced if any condition is balanced then we will do ++a
 if(flag>0)
  printf("Balanced");
 else
  printf("Imbalanced");
}

