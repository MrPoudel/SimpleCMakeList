/* Demonstration of the SinglyLinkedList */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         data;
   struct Node *next_node;
};

typedef struct Node node;
typedef struct
{
   node *start_node;
} linked_list;


void insert(int num, linked_list *list)
{
   if (list->start_node == NULL)
   {
      list->start_node            = (node *)malloc(sizeof(node));
      list->start_node->data      = num;
      list->start_node->next_node = NULL;
      printf("This is first node");
   }
   else
   {
      node *n = list->start_node;
      while (n->next_node != NULL)
      {
         n = n->next_node;
      }
      node *new_node = (node *)malloc(sizeof(node));
      new_node->data      = num;
      new_node->next_node = NULL;
      n->next_node        = new_node;
      printf("This is next node");
   }
}


void print_linked_list(linked_list ll)
{
   int  i;
   node *n;

   n = ll.start_node;      //ll.start_node;
   while (n != NULL)
   {
      printf("%d\n", n->data);
      n->next_node;
   }
}


void main()
{
   int         i;
   linked_list ll;

   ll.start_node = NULL;

   for (i = 0; i < 10; i++)
   {
      insert(i, &ll);
   }

   print_linked_list(ll);
}

