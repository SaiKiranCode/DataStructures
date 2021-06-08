 #include<stdio.h>
int main()
{
    int n,i,j,m;
   int found=0;
    int arr[100];
    printf("enter the no of elements of arr ");
    scanf("%d",&n);
    printf("enter key");
    scanf("%d",&m);
    printf("enter the elements");
    for(i=0;i<n;i++)
   { 
    scanf("%d\n",&arr[i]);
   }
   
    
    for(i=0;i<n;i++)
     { 
       if(arr[i]==m)
       { 
        found=1;
         break;
       } 
      }
  if(found=1)
  {
   printf("key element is present at %d\n",i+1);
}
else
   printf("not found");
 return 0;
}

