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
int sum(NODE *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return(1+sum(root->left)+sum(root->right));
	}
}
int leaf(NODE *root)
{
	if((root->left)==NULL&&(root->right)==NULL)
	{
		return 1;
	}
	else
	{	if(root->left==NULL)
		{
			return leaf(root->right);
		
		}
		else
		{
			if(root->right==NULL)
			{
				return leaf(root->left);
			}
			else
			{
				return leaf(root->left)+leaf(root->right);
			}
		}
	}
}
int mindata(NODE *root)
{
	NODE *temp;
	temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}
int height(NODE *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int lheight=height(root->left);
		int rheight=height(root->right);
		if(lheight>rheight)
		{
			return (lheight+1);
		}
		else
		{
		
			return (rheight+1);
		}
	
	}

}
int lookup(NODE *root,int data)
{
	int flag=0;
	if(root->data==data)
	{
		flag=1;
		return flag;
	
	}
	else
	{
		if(root->data>data)
		{
			if(root->left==NULL)
			{
				return flag;
			}
			lookup(root->left,data);
		}
		else
		{
			if(root->right==NULL)
			{
					return flag;
			}
			lookup(root->right,data);
		}
		
	
	}


}


int main()
{
	int choice;
	int value;
	int k;	
	printf("1)enter to insert 2)to print preorder list\n3)to print inorder4)to print in post order5)to find sum of nodes\n6)to find leaf nodes\n7)to find minimum data\n8)to find height of tree\n9)to search for element\n)10)toexit the program\n ");
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
				
				k=sum(root);
				printf("no of nodes is %d\n",k);
				break;
			case 6:
				printf("counting no of leaf nodes\n");
				k=leaf(root);
				printf("no of leaf nodes is %d",k);
				break;
			case 7:
				printf("finding minimum value\n");
				k=mindata(root);
				printf("minimum data is %d\n",k);
				break;
			case 8:
				printf("height of tree is ");
				k=height(root);
				printf("%d",k);
				break;
			case 9:
				printf("enter the target");
				scanf("%d",&value);
				k=lookup(root,value);
				if(k==1)
				{
					printf("elementfound\n");

				}
				else
				{
					printf("element not found\n");

				}
				break;
			case 10:
				break;
			default:
				printf("enter the correct choice\n");


		
		
		}
	
		
	}while(choice!=10);
	
	return 0;




}


