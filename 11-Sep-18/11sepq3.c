#include <stdio.h>
#define MAX 50
void swap(int *a, int *b);
void rearrange(int arr[], int n)
{
  
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
     int pos = i+1, neg = 0;
    while (pos < n && neg < pos && arr[neg] < 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
}
 

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%4d ", arr[i]);
}
 

int main()
{
    int arr[MAX];
    int n,i;
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements one by one ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
