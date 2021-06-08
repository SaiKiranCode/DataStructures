#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node NODE;
NODE *root=NULL;
struct linkedlist
{
	NODE *ptr;
	struct linkedlist *next;
};
typedef struct linkedlist LIST;
LIST *head=NULL;
void preorder(NODE *root);
NODE *Getnewnode(int data)
{
	NODE *newnode;
	
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("memory not allocated/n");
		exit(0);
	}
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
NODE *insertnode(NODE *root,int data)
{
		
	
	if(root==NULL)
	{
		
		return Getnewnode(data);
	}
	else
	{

	if(root->data>data)
	{
		root->left=insertnode(root->left,data);
		
	}
	else
	{
		
	root->right=insertnode(root->right,data);
		
	}
	return root;
	}
	
	
}
void enqueue(NODE *temp)
{
	LIST *newnode;
	newnode=(LIST *)malloc(sizeof(LIST));
	if(newnode==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	
	}
	else
	{
		if(head==NULL)
		{
			head=newnode;
			newnode->ptr=temp;
			newnode->next=NULL;
			return;
		}
		else
		{
		        LIST *node;
       			node=(LIST *)malloc(sizeof(LIST));
       			 if(node==NULL)
       			 {
               			 printf("memory not allocated\n");
             			 exit(0);

       			 }
			 else
			{
				LIST *curent;
				curent=head;
				while(curent->next!=NULL)
				{
					curent=curent->next;
				}
				curent->next=node;
				node->ptr=temp;
				node->next=NULL;	
			
			}

		
		
		}
	
	
	
	
	
	}


}
NODE *dequeue()
{
	if(head==NULL)
	{
		exit(0);
	
	}
	else
	{
		LIST *curent;
		curent=head;
		head=curent->next;
		
		return curent->ptr;
	
	
	}
	






}
void leveltraversal(NODE *root)
{
	NODE *curent;
	int  done=1;
	NODE *temp;
	temp=root;
	enqueue(temp);
	printf("levelorder ");
	while(done!=0)
	{
		curent=dequeue();
		if(curent!=NULL)
		{
			printf("%d\n",curent->data);
			
			if(curent->left!=NULL)
			{
				enqueue(curent->left);
			}
			if(curent->right!=NULL)
			{
			
				enqueue(curent->right);
			}
		}
		else
		{
			done=0;
		
		}
	
	
	
	
	
	}


}







void preorder(NODE *root)
{
	if(root!=NULL)
	{
	
	
	printf("%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
	}
}
void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);	
	
	}


}
void postorder(NODE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	
	
	}


}
NODE *minnode(NODE *root)
{
	NODE *temp;
	temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;



}


int main()
{
	int choice;
	NODE *temp;
	int value;
	int k;	
	printf("1)enter to insert 2)to print preorder list\n3)to print inorder4)to print in post order\n5)to print level order\n6)to find minimum node\n7)toexit the program\n ");	do	
	{	
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("inserting a element\n");
				printf("enter the value\n");
				scanf("%d",&value);
				if(root==NULL)
				{
					root=insertnode(root,value);
					
					break;
				}
				else
				{
					
					insertnode(root,value);
					break;
				}
				
			case 2:
				printf("printing list in preorder\n");
				preorder(root);
				break;
			case 3:
				printf("tree in inorder\n");
				inorder(root);
				break;
			case 4:
				printf("tree in postorder\n");
				postorder(root);
				break;
	
			case 5:
				leveltraversal(root);
				break;

			case 6:
				temp=minnode(root);
				printf("minimum node data is %d",temp->data);
				break;
			case 7:
				break;
			default:
				printf("enter the correct choice\n");


		
		
		}
	
		
	}while(choice!=7);

	return 0;




}


