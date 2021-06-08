
#include<stdio.h>
#define MAXSIZE 100
void Insertionsort(int q[],int n);
int main()
{
    int num,i ;
    int arr[MAXSIZE];
    printf("enter the no of elements of arr ");
    scanf("%d",&num);
    printf("enter the elements");
    for(i=0;i<num;i++)
   {
    scanf("%d",&arr[i]);
   }
  Insertionsort(arr,num);
 return 0;
}
  void Insertionsort(int q[],int n)
 {
   int i,j,temp;
   for(i=1;i<n;i++)
     {
        temp=q[i];
        j=i-1;
      while(temp<q[j]&&j>=0)
            {
             q[j+1]=q[j];
             j=j-1;   
              }
        q[j+1]=temp;
        }
       
     printf("sortet array");
     for(i=0;i<n;i++)
     {
      printf("%d\t ",q[i]);
      }
}
