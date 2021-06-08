#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100
static int i=0;
void display(int *arr)
{
	int k;
	printf("array is\n");
	for(k=0;k<i;k++)
	{
		printf("%d\n",arr[k]);
	}


}
void insert(int *arr,int data)
{
	int k;
	if(i==MAXSIZE-1)
	{
		printf("heap is full\n");

	
	}
	else
	{
		if(i==0)
		{
		
			arr[i]=data;
		}
		else
		{
			if(arr[(i-1)/2]<data)
			{
				arr[i]=data;
			}		
			else
			{
				k=i;
				while(arr[(k-1)/2]>data&&k!=0)
				{
					arr[k]=arr[(k-1)/2];
					k=(k-1)/2;
				}
				arr[k]=data;		
			
			}
		
		
		
		}
	
	
	
	
	}








}
void delete(int *arr)
{
	int k;
	k=0;
	int data;
	data=arr[i-1];
	arr[0]=arr[i-1];

	while((arr[k]>arr[2*k+1]||arr[k]>arr[2*k+2])&&(k*2+2)<i)
	{
		if(arr[2*k+1]<arr[2*k+2])
		{
			arr[k]=arr[2*k+1];
			k=2*k+1;
		}
		else
		{
			arr[k]=arr[2*k+2];
			k=2*k+2;
		}
	
		
	
	}
	arr[k]=data;


}
int main()
{
	int choice;
	int *arr;
	arr=malloc(MAXSIZE*sizeof(int));
	if(arr==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	}
	int data;
	printf("1)enter to insert data\n2)to delete min\n3) exit program\n");
	do{
	printf("enter your choice\n");
	scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				insert(arr,data);
				i++;
				display(arr);
				
				break;
			case 2:
				delete(arr);
				i=i-1;	
				display(arr);
				break;
			case 3:
				break;
			default :
				printf("enter corect choice\n");
	
	
		}
	
	
	}while(choice!=3);
	return 0;




}







