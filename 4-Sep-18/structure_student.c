#include<stdio.h>
#define MAX 50
 struct student
   {
    char name;
    int rollnumber;
    int semister;
    char degree;
    int marks[5];
   };


double display(struct student s[],int size );
 int main()
 {
  struct student s[MAX];
   int n,i,j;
   printf("enter the number of students");
   scanf("%d",&n);
   for(i=0;i<n;i++)
    {
    printf("enter the name");
   scanf("%s",&s[i].name);
   printf("enter roll no");
   scanf("%d",&s[i].rollnumber);
   printf("enter semister");
   scanf("%d",&s[i].semister);
   printf("enter degree");
   scanf("%s",&s[i].degree);
   printf("enter the marks of 5 subjects");
   for(j=0;j<5;j++)
   {
   scanf("%d",&s[i].marks[j]);
    }  
  }
display(s,n);
return 0;
}
double display(struct student s[],int size)
{
int sum,i,j;
float percent,avg;
for(i=0;i<size;i++)
{
sum=0;
for(j=0;j<5;j++)
{
sum=sum+s[i].marks[j];
 }
percent=sum/5;
printf("\n %f is percentage of %d student\n ",percent,i+1);

}
printf("\n");
for(j=0;j<5;j++)
{
avg=0;
for(i=0;i<size;i++)
{
avg=avg+s[i].marks[j];
}
avg=avg/size;
printf("\n average marks of %d subject is %f\n ",j+1,avg);

}
}

