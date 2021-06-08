#include<stdio.h>
#include<math.h>

struct point
{
 float x;
 float y;
 }p2,p1;
 double distance(struct point p3,struct point p4)
 {
  return sqrt(pow((p3.x-p4.x),2)+pow((p3.y-p4.y),2));
 }

int main()
{
 double i;
  printf("enter the x co-ordinate and y co-ordinate");
 scanf("%f%f",&p1.x,&p1.y);
 printf("enter the x co-ordinate and y co-ordinate");
 scanf("%f%f",&p2.x,&p2.y);
 i=distance(p1,p2);
 printf("\ndistance is %f\n",i);
 return 0;
}

