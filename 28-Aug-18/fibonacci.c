  #include<stdio.h>
  int fib(int n);
  int main()
{ 
  int num,f;
 printf("enter the n to find fibonacii no");
  scanf("%d",&num);
  f=fib(num-1);
  printf("%d fibonacii number is %d\n",num,f);
  return 0;
}

 int fib(int n)
 {  if(n<=1)
    return n;
   else 
    return fib(n-1)+fib(n-2);
     
          
}
