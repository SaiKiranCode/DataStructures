#include<stdio.h>
int sum(int,int);
int main()
{
   int s, a,b;
   printf("enter two numders");
   scanf("%d%d",&a,&b);
   s=sum(a,b);
   printf("sum of numbers is %d",s);
   return 0;
}
  int sum(int c, int d)
{
  int z;
  z=c+d;
  return z ;
}
