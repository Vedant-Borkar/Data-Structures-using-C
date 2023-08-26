#include<stdio.h>
#include<conio.h>

int main()
{
 int str,end,mid,n,i,j,temp,arr[100],f,flag=0;
 printf("Enter number of terms in the array\n");
 scanf("%d",&n);
 printf("Enter array elements\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 //BUBBLE SORT for ascending
 for(i=0;i<n;i++)
 {
   for(j=0;j<n-i-1;j++)
   {
    if(arr[j]>arr[j+1])
    {
     temp=arr[j+1];
     arr[j+1]=arr[j];
     arr[j]=temp;
    }
   }
 }
 //Sorted array printing
 printf("Sorted array is\n");
 for(i=0;i<n;i++)
 {
  printf("%d\n",arr[i]);

 }
 //BINARY SEARCH
 printf("Enter number to be searched\n");
 scanf("%d",&f);
 str=0;
 end=n-1;
 while(str<=end)
 {
  mid=(str+end)/2;
  if(arr[mid]==f)
  {
   printf("Found element %d at position %d",f,mid+1);
   flag++;
   break;
  }
  else if(arr[mid]>f)
   end=mid-1;
  else
   str=mid+1;
 }
 if(flag==0)
 printf("Not found");
 return 0;
 getch();

}

