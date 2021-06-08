#include<stdio.h>
#include<math.h>
struct complex
{ 
 float real;
 float image; 
}c1,c2,c3,c4,c5,c10;
float magnitude(struct complex c8)
{
return sqrt(pow(c8.real,2)+pow(c8.image,2));
 }
float addsubmult( struct complex c6,struct complex c7){

c3.real=c6.real+c7.real;
c3.image=c6.image+c7.image;  
printf("real and imaginary part on adding is %f  %f\n",c3.real,c3.image);
c4.real=c6.real-c7.real;
c4.image=c6.image-c7.image;
printf("\nreal and imaginary part  on subtraction is %f %f\n",c4.real,c4.image);
}   
    
int main()
{
  float i,j,k;
  printf("enter the real and imaginary part for first number\n");
  scanf("%f%f",&c1.real,&c1.image);
  printf("enter the real and imaginary part for second number\n");
  scanf("%f%f",&c2.real,&c2.image);
  i=magnitude(c1);
  printf("\nmagnitude of first number is %f\n",i);
  i=magnitude(c2);
  printf("\nmagnitude of second number is %f\n",i);

  addsubmult(c1,c2);
  printf("conjugate for first number is %f-%fi\n",c1.real,c1.image);
 printf("conjugate is for second number is %f-%fi\n",c2.real,c2.image);

  return 0;
 }

