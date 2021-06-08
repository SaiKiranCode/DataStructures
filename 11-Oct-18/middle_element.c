#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
  {
	 int data;
	 struct node *next;
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
		
	}
	newnode->next=head;
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
	while((temp->next)!=NULL)
	{
		temp=temp->next;
	}
        temp->next=newnode;
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
		NODE *temp;
	        temp=head;
	        head=temp->next;
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
           	NODE *prev;
	   	NODE *curent;
	  	curent=head;
		prev=head;
	   	while(curent->next!=NULL)
	  	 {
	    		prev=curent;
	     		curent=curent->next;
	       	 }
		 if(prev==curent)
		 {
		 	printf("list is empty");
			return;
		 }
	  	 prev->next=NULL;
		 free(curent);
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
void middle_element()
{
	NODE *temp;
        temp=head;
        int total=0;
        while(temp!=NULL)
        {
                total++;
                temp=temp->next;
        }
	NODE *curent;
	curent=head;
	int x=0;
	while(curent!=NULL)
	{
		x++;
		if((total%2==0)&&(x==(total/2)))
		{
                   	printf("middle element are %d \n",curent->next->data);
			return;	
		}
		if((total%2==1)&&(x==total/2))
		{
			printf("middle element are %d\n",curent->next->data);
			return;
		}

		curent=curent->next;
	}


}
int main()
{
      int choice;
      printf("1)to insert  from the front \n 2)to delete from the front\n 3) to insert from the end\n 4) to delete from the end\n 5) to display the list\n6)to find the middle element\n");
     do
      {
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
		 case 6:   
			   middle_element();
			   exit(0);
			   break;
		 default :
			    printf("enter the correct choice :");
	}
         
	 
   }while(choice!=6);
       return 0;
}

    
    
    
    
    
    
    
    
    
    

















