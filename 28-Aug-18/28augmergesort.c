#include<stdio.h>
#include<stdlib.h>
void merge(int *a,int l,int m,int r)
{
	int i,j,k;
	int n1;
	int n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	R[j]=a[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
			k++;
		}
		else
		{
			a[k]=R[j];
			j++;
			k++;
		
		}
	
	
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	
	
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	
	}


}
void mergesort(int *a,int l,int r)
{
	int m;
	
	if(l<r)
	{
		m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	
	}



}

int main()
{
 int i,n;
 int *arr;
 
 printf("\n enter the number of elements ");
 scanf("%d",&n);
 arr=(int*)malloc(n*sizeof(int));
 if(arr==NULL)
 {
 printf("\n memory allocation failed");
 exit(0);
 }
printf("enter the elements one by one");
for(i=0;i<n;i++)
{
 scanf("%d",&arr[i]);
}
printf("array is");
for(i=0;i<n;i++)
printf("\n%d\n",arr[i]);
mergesort(arr,0,n-1);
printf("array after sorting is \n");
for(i=0;i<n;i++)
printf("\n%d\n",arr[i]);

return 0;
}


