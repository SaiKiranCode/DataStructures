#include<stdio.h>
#define MAXSIZE 100
int bubblesort(int q[],int n);
int binarysearch(int a[],int key,int n);
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
 int i,j,temp,key;
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
printf("enter the key");
scanf("%d",&key);
 binarysearch(q,key,n);
}
int binarysearch(int a[],int key,int n)
{
  int low,high,mid,key;
 int a[n];
  low=0;
  high=n-1;
 do{
   mid=(high+low)/2;
   if(a[mid]>key)
   high=mid-1;
  else
  if(key>a[mid])
  low=mid+1;
  }while((a[mid]!==key)&&(low<=high));
 
if(a[mid]==key)
printf("element is found at %d",mid+1);
else
printf("element not found");
}
























     }
