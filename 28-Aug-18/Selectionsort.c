
#include<stdio.h>
#define MAXSIZE 100
void selectionsort(int q[],int n);
int main()
{
    int num,i ;
    int arr[MAXSIZE];
    printf("enter the no of elements of arr ");
    scanf("%d",&num);
    printf("enter the elements");
    for(i=1;i<=num;i++)
     {
      scanf("%d",&arr[i]);
     }
   
 selectionsort(arr,num);
  return 0;
}
  void selectionsort(int q[],int n)
 {
    int i,j,temp,min;
    for(i=1;i<=n-1;i++)
  {  
   min=i;
    for(j=i+1;j<=n;j++) 
     {
      if(q[j]<q[min])
      { 
        min=j;
      }
  temp=q[i];
  q[i]=q[min];
  q[min]=temp;
    }
 }
  printf("sortet array");
  for(i=1;i<=n;i++)
     {
      printf("%d\t ",q[i]);
      }
}
