#include <stdio.h>
#include <stdlib.h>
#define max 50
 struct node
   {
    int a;
    struct node *next;
   };
  void generate(struct node **);
  void display(struct node *);
  void stack_reverse(struct node **);
  void delete(struct node **);
  int main()
 {
 struct node *head = NULL;
 generate(&head);
 printf("\nThe sequence of contents in stack\n");
 display(head);
 printf("\nInversing the contents of the stack\n");
 stack_reverse(&head);
 printf("\nThe contents in stack after reversal\n");
 display(head);
 delete(&head);
 return 0;
   }
 void stack_reverse(struct node **head)
 {
   struct node *temp, *prev;
   if (*head == NULL)
  {
   printf("Stack does not exist\n");
  }
 else if ((*head)->next == NULL)
        {
          printf("Single node stack reversal brings no difference\n");
         }
else if ((*head)->next->next == NULL)
      {
         (*head)->next->next = *head;
          *head = (*head)->next;
          (*head)->next->next = NULL;
 }
 else
 {
  prev = *head;
  temp = (*head)->next;
  *head = (*head)->next->next;
  prev->next = NULL;
while ((*head)->next != NULL)
{
  temp->next = prev;
  prev = temp;
  temp = *head;
  *head = (*head)->next;
 }
 temp->next = prev;
 (*head)->next = temp;
 }
   }
  void display(struct node *head)
 {
  if (head != NULL)
  {
   printf(" %d\n", head->a);
   display(head->next);
   }
 }
 void generate(struct node **head)
 {
  int num, i;
  int array[max];
  struct node *temp;
   printf("Enter length of stack ");
   scanf("%d", &num);
  printf("enter elements in the stack");
 for(i=0;i<num;i++)
  scanf("%d",&array[i]);
   for (i =0; i<num; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->a = array[i];
    if (*head == NULL)
  {
   *head = temp;
   (*head)->next = NULL;
   }
  else
  {
   temp->next = *head;
   *head = temp;
   }

   }
   }
 void delete(struct node **head)
 {
 struct node *temp;
 while (*head != NULL)
 {
  temp = *head;
  *head = (*head)->next;
  free(temp);
  }
 }


