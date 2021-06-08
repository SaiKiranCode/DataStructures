#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]) 
{  int i,sum,a=0,b=0;
  for(i=0;i<strlen(argv[1]);i++)
 { 
   a=a*10;
   a+=argv[1][i]-48;
 } 
 for(i=0;i<strlen(argv[2]);i++)
 {
  b=b*10;
  b+=argv[2][i]-48;
  }
 sum=a+b;
 printf("\nsum=%d\n",sum);
 return 0;
}

