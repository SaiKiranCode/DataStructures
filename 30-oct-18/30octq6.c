#include<stdio.h>
#include<stdlib.h>

void degree(int **arr,int n)
{
	int degree,i,j;
	int sum=0;
	for(i=0;i<n;i++)
	{
		degree=0;	
		for(j=0;j<n;j++)
		{
			if(arr[i][j]==1)
			{
				degree=degree+1;
			}
		
		}
		printf("degree of %d is %d\n",i+1,degree);
		sum=sum+degree;
	
	
	
	}
	printf("no of edges is %d\n",sum/2);


}
int main()
{
	int **a;
	int i,j;
	int n;
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	if(a==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	
	}
	for(i=0;i<n;i++)
	{
		a[i]=malloc(n*sizeof(int));
	}
	printf("enter the 1 if edge is present");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("vertices are %d ,%d\n",i+1,j+1);
			printf("enter the value ");
			scanf("%d",&a[i][j]);
			
		}
	
	
	
	}
	printf("array is \n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        
                        
                        printf(" %d ",a[i][j]);

                }
		printf("\n");


        }
	
	degree(a,n);


}
