/* structure is used to return two values from minMax() */
#include<stdio.h> 

struct pair 
{ 
int min; 
int max; 
}; 

struct pair getMinMax(int arr[], int low, int high) 
{ 
struct pair minmax, mml, mmr;	 
int mid; 
	
/* If there is only on element */
if (low == high) 
{ 
	minmax.max = arr[low]; 
	minmax.min = arr[low];	 
	return minmax; 
}	 
	
/* If there are two elements */
if (high == low + 1) 
{ 
	if (arr[low] > arr[high]) 
	{ 
		minmax.max = arr[low]; 
		minmax.min = arr[high]; 
	} 
	else
	{ 
		minmax.max = arr[high]; 
		minmax.min = arr[low]; 
	} 
	return minmax; 
} 
	
/* If there are more than 2 elements */
mid = (low + high)/2; 
mml = getMinMax(arr, low, mid); 
mmr = getMinMax(arr, mid+1, high); 
	
/* compare minimums of two parts*/
if (mml.min < mmr.min) 
	minmax.min = mml.min; 
else
	minmax.min = mmr.min;	 

/* compare maximums of two parts*/
if (mml.max > mmr.max) 
	minmax.max = mml.max; 
else
	minmax.max = mmr.max;	 

return minmax; 
} 
#include<stdlib.h>
int main()
{
 int i,n;
 int *array;
 
 printf("\n enter the number of elements ");
 scanf("%d",&n);
 array=(int*)malloc(n*sizeof(int));
 if(array==NULL)
 {
 printf("\n memory allocation failed");
 exit(0);
 }
printf("enter the elements one by one");
for(i=0;i<n;i++)
{
 scanf("%d",&array[i]);
}


struct pair minmax = getMinMax(array, 0, n-1); 
printf("nMinimum element is %d", minmax.min); 
printf("nMaximum element is %d", minmax.max); 
getchar(); 
} 

