#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20 
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node NODE;
NODE *root=NULL;
struct stack
{
	int size;
	int top;
	NODE **arr;

};
struct stack *createstack(int size)
{
	struct stack *stack;
	stack=(struct stack *)malloc(sizeof(struct stack));
	if(stack==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	
	}
	stack->top=-1;
	stack->size=size;
    stack->arr=(NODE **)malloc(stack->size*sizeof(NODE *));
	return stack;

}
void push(struct stack *stack,NODE *temp)
{
	stack->top++;
	stack->arr[stack->top]=temp;

}
NODE *pop(struct stack *stack)
{
	NODE *temp;
	temp=stack->arr[stack->top];
	stack->top--;
	return temp;

}
void postorderwithoutrec(NODE *root)
{
	struct stack *s1;
	struct stack *s2;
	s1=createstack(MAXSIZE);
	s2=createstack(MAXSIZE);
	NODE *temp;
	temp=root;
	push(s1,temp);
	while(s1->top!=-1)
	{
		temp=pop(s1);
		push(s2,temp);
		if(temp->left!=NULL)
		{
		push(s1,temp->left);
		}
		if(temp->right!=NULL)
		{
		push(s1,temp->right);
		}
	
	}
	while(s2->top!=-1)
	{
		temp=pop(s2);
		printf("%d\n",temp->data);
	
	}



}
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
void leaf(NODE *root)
{
	if(root!=NULL)
	{
		
		if(root->left==NULL&&root->right==NULL)
		{
			printf("leaf %d \n",root->data);
			
		}
		else
		{
		
			printf("internal node %d \n",root->data);
			
		}
		leaf(root->left);
		leaf(root->right);
	
	
	}




}

int main()
{
	int choice;
	int value;
	int k;	
	printf("1)enter to insert 2)to print preorder list\n3)to print inorder4)to print in post order\n5 to print postorderwithoutrecursion\n6)toexit the program\n ");	do		{	
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
				printf("postorder is \n");
				postorderwithoutrec(root);
				break;

			case 6:
				leaf(root);
				break;
			case 7:
				break;
			default:
				printf("enter the correct choice\n");


		
		
		}
	
		
	}while(choice!=7);

	return 0;




}


