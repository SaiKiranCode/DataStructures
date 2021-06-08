#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
struct node
{
	int data;
	struct node *next;


};
typedef struct node NODE;
#include"nodequeue.c"
NODE *createnewnode(int data)
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	
	}
	newnode->data=data;
	newnode->next=NULL;
	return newnode;





}
struct graph
{
	int vertices;
	int edge;
	NODE **arr;
};
typedef struct graph GRAPH;

GRAPH *creategraph(int vertices)
{
	GRAPH *graph;
	graph=(GRAPH *)malloc(sizeof(GRAPH));
	if(graph==NULL)
	{
		printf("memory not allocated\n");
		exit(0);

	
	
	}
	graph->vertices=vertices;
	graph->arr=(NODE **)malloc(graph->vertices*sizeof(NODE *));
	if(graph->arr==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	}
	graph->edge=0;
	return graph;



}
void edge(GRAPH *graph,  int u,int v)
{
	NODE *newnode;
	newnode=createnewnode(v);
	if(graph->arr[u]==NULL)
	{
		graph->arr[u]=newnode;
	}
	else
	{
		NODE *temp;
		temp=graph->arr[u];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	
	
	
	}


}
void display(GRAPH *graph)
{
	int n;
	NODE *temp;
	int count=0;
	printf("enter the vertex to know its adjacent\n");
	scanf("%d",&n);
	if(graph->arr[n]==NULL)
	{
		printf("vertex is isolated\n");
	
	}
	else
	{
		temp=graph->arr[n];
		printf("vertices adjacent to it is ");
		while(temp!=NULL)
		{
			count++;
			printf("%d\t",temp->data);
			temp=temp->next;
		
		}
		printf("vertices adjacent are %d\n",count);
		printf("total no of edges is %d\n",graph->edge);
	
	
	
	}






}
void breathfirstsearch(GRAPH *graph,int v,int *c,int n)
{
	int i;

	if(graph->arr[v]==NULL)
	{
		printf("vertex is isolated\n");
	}
	else
	{
		c[v]=1;
		NODE *temp;
		QUEUE *queue;
		queue=createqueue();
		printf("vertices conected to v are\n");
		temp=graph->arr[v];
		enqueue(temp,queue);
		while(isempty(queue)==1)
		{
		
			temp=dequeue(queue);
			while(temp!=NULL)
			{
				if(c[temp->data]==0)
				{
					printf("%d\t",temp->data);
					enqueue(graph->arr[temp->data],queue);
					c[temp->data]=1;
				
				}
				temp=temp->next;
			
			
			
			
			
			}
		
		
		
		}
		int flag;
		flag=0;
		for(i=0;i<n;i++)
		{
			if(c[i]==1)
			{
			
			}
			else
			{
				flag=1;
			
			}
		
		
		
		}	
		if(flag==1)
		{
			printf(" it is not conected\n");
		}
		else
		{
			printf("it is conected\n");
		
		}
	
	
	}
  





}

int main()
{
	int n;
	GRAPH *graph;
	int v,u;
	int i;
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	graph=creategraph(n);
	int choice;
	printf("1)to make edge between verties\n2)to display\n3)to breath first search\n4)to exit the program\n");	int *c;
	c=(int *)malloc(n*sizeof(int));
	if(c==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	
	}
	for(i=0;i<n;i++)
	{
		c[i]=0;
	}

	
	do{
	printf("enter the choice\n");
	scanf("%d",&choice);
	
	
		switch(choice)
		{
			case 1:
				printf("enter the vertices in which edge is present\n");
				scanf("%d %d",&u,&v);
				edge(graph,u,v);
				edge(graph,v,u);
				graph->edge++;
				
				break;
			case 2:
				 display(graph);
				break;
			case 3:
				  printf("enter the vertex\n");
      				  scanf("%d",&v);

				breathfirstsearch(graph,v,c,n);
				   for(i=0;i<n;i++)
  				      {
               					 c[i]=0;
     				   }

				break;
				
			case 4:
				break;
		
		
		
		}
	
	
	
	
	}while(choice!=4);
return 0;






}










