#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
  {
	 int data;
	 struct node *next;
  };
typedef struct node NODE;
void display();
NODE *head=NULL;
 NODE *Getnewnode(int n)
{
   	 NODE *newnode; int value;
   	 newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
	 	printf("memory not allocated");
	        exit(0);	
	
	}
	else
	{	
		printf("\nenter the coefficient of x^%d\n",n);
		scanf("%d",&value);
		newnode->data=value;
		newnode->next=NULL;
		return newnode;
	}
 }

void insert_at_end(int n)
{
	
	NODE *newnode;
        newnode=Getnewnode(n);
        if(head==NULL)
	{
        	printf("list is empty\n");
	      	printf("creating a list\n");
        	head=newnode;
		return;
	
	}
        
	NODE *temp;
	temp=head;
	while((temp->next)!=NULL)
	{
		temp=temp->next;
	}
        temp->next=newnode;
	display();	
}


void display()
{
	if(head==NULL)
	{
	      printf("list is empty\n");
	      return;
	}
        NODE *temp;
        temp=head;
	printf("list is : ");
	while(temp->next!=NULL)
	{
		  printf("%d-> ",temp->data);
		  temp=temp->next;
	}
       	printf("%d",temp->data);
	printf("\n");
}
float value(float x,int n)
{
	int i;
	float sum=0;
	NODE *temp;
	temp=head;
	for(i=n;i>=0;i--)
	{
		sum=sum+pow(x,i)*temp->data;
		temp=temp->next;
	
	}
	printf("value of polynomial is %f",sum);
	return sum;
	

}
int main()
{
	int n;
	float x;
	float k;
     	printf("enter the degree of polynomial\n ");
	scanf("%d",&n);	
     	int i;
	for(i=n;i>=0;i--)
	{
		insert_at_end(i);
	
	}
	printf("enter the value of x");
	scanf("%f",&x);
	value(x,n);
       return 0;
}

    
    
    
    
    
    
    
    
    
    

















