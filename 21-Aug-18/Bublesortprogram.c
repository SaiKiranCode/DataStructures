#include<stdio.h>
#define MAXSIZE 100
void bubblesort(int q[],int n);
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
  bubblesort(arr,num);
 return 0;
}
void bubblesort(int q[],int n)
{ 
 int i,j,temp;
 for(i=0;i<n;i++)
     {
         for(j=0;j<(n-i-1);j++)
            {
                if(q[j]>q[j+1])
                     {
                       temp=q[j+1];
                       q[j+1]=q[j];
                       q[j]=temp;

                        }

             }
       }
     printf("sortet array");
     for(i=0;i<n;i++)
     {
      printf("%d\t ",q[i]);
      }

}

