#include<stdio.h>
#include<stdlib.h>
void display(int **a,int row,int column);
int **creatematrix(int row,int column)
{
	int **a;
	int i,j;
	a=(int**)malloc(row*sizeof(int *));
	if(a==NULL)
	{
		printf("memory not allocated");
		exit(0);
	
	
	}
	for(i=0;i<row;i++)
	{
		a[i]=(int *)malloc(column*sizeof(int));
		if(a[i]==NULL)
		{
			printf("memory not allocated\n");
			exit(0);
		}
	
	}
	printf("enter the elements in matrix\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			scanf("%d",&a[i][j]);
		
		}
	
	
	
	
	}
	display(a,row,column);
	return a;




}
void display(int **a,int row,int column)
{
	int i,j;
	printf("matrix is\n");
	for(i=0;i<row;i++)
        {
                for(j=0;j<column;j++)
                {
                        printf("%d\t",a[i][j]);
			
                }
		printf("\n");



        }





}
int **matrixmultiply(int **a,int **b,int r1,int c1,int c2)
{

       int **c;
        int i,j,k;
        c=(int**)malloc(r1*sizeof(int *));
        if(c==NULL)
        {
                printf("memory not allocated");
                exit(0);


        }
        for(i=0;i<r1;i++)
        {
                c[i]=(int *)malloc(c2*sizeof(int));
                if(c[i]==NULL)
                {
                        printf("memory not allocated\n");
                        exit(0);
                }

        }
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			c[i][j]=0;
			for(k=0;k<c1;k++)
			{
				c[i][j]=a[i][k]*b[k][j]+c[i][j];
			}
		
		}
	
	
	
	
	}
	return c;



}
int main()
{
	int **a;
	int **b;
	int **c;
	int r1,c1,r2,c2;
	printf("enter the no of rows in martix 1");
	scanf("%d",&r1);
	printf("enter the no of	columns in matrix 1  ");
	scanf("%d",&c1);
	printf("enter elements in matrix 1");
     	a=creatematrix(r1,c1);
        printf("enter the no of rows in martix 2");
        scanf("%d",&r2);
        printf("enter the no of columns in matrix 2 ");
        scanf("%d",&c2);
        printf("enter elements in matrix 2");
        b=creatematrix(r2,c2);
	if(c1!=r2)
	{
		printf("matrix multiplication not possible");
	
	}
	else
	{
		c=matrixmultiply(a,b,r1,c1,c2);
	/*	printf("matrix 1 is\n");
		display(a,r1,c1);
		printf("matrix 2 is\n");
		display(b,r2,c2);*/
		printf("matrix 3 is\n");
		display(c,r1,c2);
	}

	return 0;


}
