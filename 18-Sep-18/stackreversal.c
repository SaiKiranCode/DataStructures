#include<stdio.h>
#include<stdlib.h>
#define bool int
#define max 10 
struct sNode
{
    char data;
    struct sNode *next;
};
 
void push(struct sNode** top_ref,int new_data);
int pop(struct sNode** top_ref);
bool isEmpty(struct sNode* top);
void print(struct sNode* top);
 

void insertAtBottom(struct sNode** top_ref, int item)
{
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else
    {
 
       
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item); 
        push(top_ref, temp);
    }
}

void reverse(struct sNode** top_ref)
{
    if (!isEmpty(*top_ref))
    {
        
        int temp = pop(top_ref);
        reverse(top_ref);
        insertAtBottom(top_ref, temp);
    }
}
 

int main()
{
   int i,n;
   int array[max];
   printf("enter the no of elements in stack");
   scanf("%d",&n);
   printf("enter the elements in stack");
   for(i=0;i<n;i++)
   scanf("%d",&array[i]);
    struct sNode *s = NULL;
 for(i=0;i<n;i++)
{
 push(&s,array[i]);
 } 
 printf("\n Original Stack ");
    print(s);
    reverse(&s);
    printf("\n Reversed Stack ");
    print(s);
    return 0;
}
 

bool isEmpty(struct sNode* top)
{
    return (top == NULL)? 1 : 0;
}
 

void push(struct sNode** top_ref, int new_data)
{
  struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode));
  if (new_node == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
 new_node->data = new_data;
 new_node->next = (*top_ref);
 (*top_ref) = new_node;
}
int pop(struct sNode** top_ref)
{
    char res;
    struct sNode *top;
    if (*top_ref == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
 }
}
 
void print(struct sNode* top)
{
    printf("\n");
    while (top != NULL)
    {
        printf(" %d ", top->data);
        top = top->next;
    }
}


