#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
  {
	 int data;
	 struct node *next;
	 struct node *prev;
  };
typedef struct node NODE;
void display();
NODE *head=NULL;
 NODE *Getnewnode()
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
		printf("\nenter the value\n");
		scanf("%d",&value);
		newnode->data=value;
		newnode->next=NULL;
		newnode->prev=NULL;
		return newnode;
	}
 }
void insert_at_front()
{
	NODE *newnode;
	newnode=Getnewnode();
        if(head==NULL)
	{
		printf("list is empty\n");
		printf("creating a list\n");
		head=newnode;
		return;

	}
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	display();
	
}
void insert_at_end()
{
	
	NODE *newnode;
        newnode=Getnewnode();
        if(head==NULL)
	{
        	printf("list is empty\n");
	      	printf("creating a list\n");
        	head=newnode;
		return;
	
	}
        
	NODE *temp;
	temp=head;
	NODE *curent;
	curent=head;
	while((temp->next)!=NULL)
	{

		temp=temp->next;
		temp->prev=curent;
		curent=curent->next;

	}
	
        temp->next=newnode;
	newnode->prev=temp;
	display();	
}
void delete_at_front()
{
	if(head==NULL)
	{
		printf("list is empty\n");
		return;   
	}
	else
	{
		NODE *curent;
		NODE *temp;
	        temp=head;
	        head=temp->next;
		if(temp->next==NULL)
		{
		  head=NULL;
		  free(temp);
		  printf("list is empty");
		  return;
		
		}
		curent=head;
	
		curent->prev=NULL;
	        free(temp);
	       	
		if(head==NULL)
		{
		  printf("list is empty");
		  return;
		}
		else
		{
			display();
		}
		
	}
	
}
void delete_at_end()
{
	if(head==NULL)
        {
               printf("list is empty\n");
               return;       
        }
	else
	{
           	NODE *temp;
	   	NODE *curent;
	  	curent=head;
		temp=head;
	   	if(head->next==NULL)
		{
		 free(temp);
		 head=NULL;
		 printf("list is empty");

		 return;
		}
		temp=head->next;
		while(temp->next!=NULL)
	  	 {
	    		
	     		temp->prev=curent;
			curent=curent->next;
			temp=temp->next;

	       	 }
		
		
		temp->prev=NULL;
		curent->next=NULL;
		free(temp);
		 
		 
	  	 
		 
		 
		 display();
		  


	  }

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


int main()
{
      int choice;
      int position;
      printf("1)to insert  from the front \n 2)to delete from the front\n 3) to insert from the end\n 4) to delete from the end\n 5) to display the list\n6)to insert at i th position\n7)to exit the program\n"); 
   do{
          printf("enter the choice");
          scanf("%d",&choice);
	  switch(choice)
	  {
		  case 1:
			    printf("inserting a element from  front\n");
			    insert_at_front();
			    break;
		  case 2:
			    printf("deleting from front\n");
			    delete_at_front();
			    break;
		  case 3:
			    printf("inseting a element from end\n ");
			    insert_at_end();
			    break;
		  case 4:
			    printf("deleting a element  from end\n");
			    delete_at_end();
			    break;
		  case 5:
			    display();
			    break;
/*		case 6:
			    printf("enter the position to insert");
			    scanf("%d",&position);
			    insert_ith_position(position);
			    break;*/
		case 7:
			   exit(0);
		 default :
			    printf("enter the correct choice :");
	}
         
   }while(choice!=7);
       return 0;
}

    
    
    
    
    
    
    
    
    
    

















