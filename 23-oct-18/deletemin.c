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

void deletemin(NODE *root)
{
	NODE *temp;
	NODE *curent;
	temp=root;
	while(temp->left!=NULL)
	{
		curent=temp;
		temp=temp->left;
	}
	if(temp==root)
	{
		curent=temp;
		root=temp->right;
		free(curent);
	}
	else
	{
		if(temp->right==NULL)
		{
			free(temp);
			curent->left=NULL;
		}
		else
		{
			
				curent->left=temp->right;
				free(temp);
		}
		
	}


}










int main()
{
	int choice;
	int value;
	int k;	
	printf("1)enter to insert 2)to print preorder list\n3)to print inorder4)to print in post order5)to delete min\n6)toexit the program\n ");
	do	
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
				deletemin(root);
				break;
			case 6:
				break;
			default:
				printf("enter the correct choice\n");


		
		
		}
	
		
	}while(choice!=6);
	
	return 0;




}


