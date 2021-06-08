#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int front=-1;
int rear=-1;
void enqueue(int *arr,int data)
{
	rear++;
	arr[rear]=data;

}
int dequeue(int *arr)
{
	front++;
	return arr[front];

}
void insert(int *arr,int data)
{
	int temp;
	int flag=0;
	int rear1;
	if(rear==-1)
	{
		enqueue(arr,data);
	
	}
	else
	{
		rear1=rear;
		if(arr[rear]<data)
		{
			enqueue(arr,data);
			return;
		
		}
				
		while(rear1!=front)
		{
			temp=dequeue(arr);
			if(temp>data)
			{
				if(flag==0)
				{
					enqueue(arr,data);
					flag=1;
				}
				enqueue(arr,temp);
			
			
			}
			else
			{
					enqueue(arr,temp);
					
					
			}
			
		
		
		
		}	
	}











}
int delete(int *arr)
{
	front++;
	return arr[front];

}
void display(int *arr)
{
	int i;
	printf("queue is");
	if(front==rear)
	{
		printf("empty\n");
	}
	else
	{
		for(i=front+1;i<=rear;i++)
		{
			printf(" %d\t",arr[i]);
	
		}
		printf("\n");
	}


}
int main()
{
        int choice;
        int *arr;
	int min;
        arr=malloc(MAXSIZE*sizeof(int));
        if(arr==NULL)
        {
                printf("memory not allocated\n");
                exit(0);
        }
        int data;
        printf("1)enter to insert data\n2)to delete min\n3) exit program\n");
        do{
        printf("enter your choice\n");
        scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                                printf("enter the data\n");
                                scanf("%d",&data);
                                insert(arr,data);
                                display(arr);
			       	break;
                        case 2:
                         	
            			if(front==rear)
				{
					printf("queue is enpty\n");
				
				
				}
				else
				{
					min=delete(arr);
					printf("minimum is %d\n",min);
                               		display(arr);
				}
                                break;
                        case 3:
                                break;
                 
			default :
				printf("enter the corect choice\n");
		}

	}while(choice!=3);
	return 0;
}








