#include<stdio.h>
void removerep(int position,int a[],int size);
 int main()
{
	int i,j,size,count=0,k,position;
	printf("Enter number of elements\n");
	scanf("%d",&size);
	int a[size],*temp;
	printf("Enter numbers\n");
	for(i=0;i<size;i++)
	{
		 scanf("%d",&a[i]);
	}

	temp=a;

	for(i=0;i<size;i++)
	{
		 for(j=i+1;j<size;)
		 {
		    if(a[i]==a[j])
		    {

			     removerep(j,a,size);
        		      size--;
       		     }
   		    else
   		 {
     			 j++;
    		 }
	 }
}

	printf("After removing repeated elements\n");
	  for(i=0;i<size;i++)
	 {

		  printf(" %d ",a[i]);
	 }
	 printf("length of array is %d",size);
}

void removerep(int position,int a[],int size)
{
	 int i;

 	 for(i=0;i<size;i++)
        {
	     if(i<position)
	     {
		      a[i]=a[i];
	     }
   		  if(i>=position)
   		  {
  		    a[i]=a[i+1];
 		    }

        }
  
  
}
