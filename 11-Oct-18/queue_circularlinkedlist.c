#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
 	struct node *next;
 	int data;
};
typedef struct node NODE;
NODE *last=NULL;
NODE *Getnewnode()
{
	int value;
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	}
	else
	{
		printf("enter the data\n");
		scanf("%d",&value);
		newnode->data=value;
	        newnode->next=NULL;
		return newnode;
	}


}
void display()
{
	if(last==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	NODE *temp;
	temp=last->next;
	printf("queue is :");
	while(temp!=last)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	
	}
	printf("%d",temp->data);



}
void enqueue()
{
	NODE *newnode;
	newnode=Getnewnode();
	if(last==NULL)
	{
		last=newnode;
		last->next=last;
		display();
		return;
	}
	newnode->next=last->next;
	last->next=newnode;
	last=newnode;
	display();


}
void dequeue()
{
	if(last==NULL)
	{
		printf("list is empty\n");
		return;
	}
	NODE *temp;
	NODE *curent;
	temp=last->next;
        if(last->next==last)
	{
		curent=last;
		printf("element dequeued is %d",curent->data);
		free(curent);
		last=NULL;
		return;
	}	
	last->next=temp->next;
	curent=temp;
	printf("element dequeued is %d",curent->data);
	free(curent);
	display();


}
int main()
{
	int choice;
	printf("1)to enqueue an element\n 2)to dqueue an element\n 3)to display the list\n 4)to exit the program\n");
	do
	{
		printf("\nenter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enqueuing an element\n");
				enqueue();
				break;
			case 2:
				printf("dequeuing  an element\n");
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
		
			default:
				printf("enter corect choice\n")	;
				
		
		
		
		
		}
	
	
	
	}while(choice!=4);
	return 0;







}







