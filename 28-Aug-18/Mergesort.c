#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void merge(int arr[],int l,int m,int r)
{   
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  int L[n1],R[n2];
  for(i=0;i<n1;i++);
  {
    L[i]=arr[l+i];
   }
  for(j=0;j<n2;j++)
   {
    R[j]=arr[m+1+j];  
     }
  i=0;
  j=0;
  k=l;
 while(i<n1&&j<n2)
 {
   if(L[i]<=R[j])
{
arr[k]=L[i];
i++;
}
else
{
arr[k]=R[j];
j++;
}
k++;
 }
while(j<n2){
arr[k]=R[j];
j++;
k++;
}
while(i<n1){
arr[k]=L[i];
i++;
k++;
}
}

 void mergesort(int arr[],int l,int r){
 if(l<r)
 {
   int m=l+(r-l)/2;
  mergesort(arr,l,m);
  mergesort(arr,m+1,r);
  merge(arr,l,m,r);
  }
}
int main(){
 int arr[MAX];
  int n,i;
  printf("enter the no elements in array");
  scanf("%d",&n);
  printf("enter the elements ");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
mergesort(arr,0,n-1);
printf("sorted array is");
for(i=0;i<n;i++)
printf("%d\n",arr[i]);
return 0;






}


