#include<stdio.h>
#define max 10
struct stack
{
 int top;
 int stackarray[max];
};
 int isempty(struct stack tmp)
 {
    printf("%d",tmp.top);
   if(tmp.top==-1)
    {
      return 0;
    }
   else 
   {
      return 1;
    }
  }
 
 void push(struct stack *tmp,int item)
 {
    if(tmp->top==max)
    {
     printf("data over flow");
    }
    else
   {
    tmp->top++;
    tmp->stackarray[tmp->top]=item;
    printf("the item %d pushed in %d\n",item,tmp->top);
   } 
 }
void pop(struct stack *tmp)
{
  if(tmp->top==-1)
  {
   printf("dataover flow");
  }
 else
{
 printf("the data poped out is %d\n",tmp->stackarray[tmp->top--]);
}
}
 void main()
 {
 int i;
 struct stack st={-1};
 if(isempty(st))
 { 
 printf("stack is empty");
  }
 else
{
 printf("stack is not empty");
}

for(i=0;i<=max-1;i++)
 {
  push(&st,i);
 } 
 for(i=0;i<=max-1;i++)
 { 
  pop(&st);
 }

}












