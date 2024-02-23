#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef struct ll
{
  Node *head;
  Node *tail;
} LinkedList;

int main()
{
  LinkedList list = {
      .head = NULL,
      .tail = NULL};
  for (int i = 0; i < SIZE; i++)
  {
    Node *new_node = malloc(sizeof *new_node);
    if (new_node == NULL)
      return 0;

    // if(list.head==NULL)
    //   list.head = new_node;
    // else
    //   list.tail->next = new_node;
    // list.tail = new_node;

    // new_node->next = list.head;
    // list.head = new_node;
  }

  return 0;
}