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
void insert_ith_position(int position)
{
	NODE *temp;
	NODE *newnode;
	newnode=Getnewnode();
	temp=head;
	int count=1;
	int k=1;
	if(position==1)
	{
		newnode->next=head;
        	head=newnode;
        	display();
		return;
	}
	while(temp!=NULL)
	{ 
		k++;
	 	count++;
		if(count==position)
		{
			 break;
		}
		if(position<0||position==0)
		{
		 	printf("enter the correct position\n");
			return;
		}
		temp=temp->next;
	}
	if(k<position)
	{
		printf("enter the correct position\n ");
		return;
	
	}

	newnode->next=temp->next;
	temp->next=newnode;
	display();

}
void delete_ith_position(int position)
{
        NODE *temp;
        NODE *curent;
        temp=head;
        int count=1;
        int k=1;
        if(position==1)
        {
                head=temp->next;
                free(temp);
                display();
                return;
        }
        while(temp!=NULL)
        {
                k++;
                count++;
                if(count==position)
                {
                         break;
                }
                if(position<0||position==0)
                {
                        printf("enter the correct position\n");
                        return;
                }
                temp=temp->next;
        }
	if(temp->next==NULL)
	{
		printf("enter the corect position\n");
		return;
	}
        if(k<position)
        {
                printf("enter the correct position\n ");
                return;

        }
	curent=temp->next;
	temp->next=curent->next;
	free(curent);
	display();



}
void find_position(int value)
{
	NODE *temp;
	int count=0;
	int flag=0;
	int k;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		if(temp->data==value)
		{
			flag=1;
			k=count;
		        printf("\nvalue is present at %d\n",k);
		}
	temp=temp->next;
	}
	if(flag==0)
	
	{
	  printf("value is not present\n");
	}




}


int main()
{
      int choice;
      int value;
      int position;
      printf("1)to insert  from the front \n 2)to delete from the front\n 3) to insert from the end\n 4) to delete from the end\n 5) to display the list\n6)to insert at i th position\n7)to exit the program\n8)to delete at ith position\n9)to find position of data\n");  
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
		case 6:
			    printf("enter the position to insert");
			    scanf("%d",&position);
			    insert_ith_position(position);
			    break;
		case 7:
			   exit(0);

	        case 8:
			   printf("enter the position to delete");
			   scanf("%d",&position);
			   delete_ith_position(position);
			   break;
		case 9:
			   printf("enter the value\n");
			   scanf("%d",&value);
			    find_position(value);
			    break;
		default :
			    printf("enter the correct choice :");
	}
         
   }while(choice!=7);
       return 0;
}

    
    
    
    
    
    
    
    
    
    

















