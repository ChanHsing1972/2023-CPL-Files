#include <stdio.h>
#include <stdlib.h>
#define N 15

typedef struct node
{
  int top;
  int value[N];
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
  int n, m, x, y;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    Node *new_node = malloc(sizeof *new_node);
    if (new_node == NULL)
      return 0;
    new_node->value[0] = i;
    new_node->top = 1;
    // Two ways to insert:
    // 1. left => right
    // if(list.head==NULL)
    //   list.head = new_node;
    // else
    //   list.tail->next = new_node;
    // list.tail = new_node;
    // 2. right => left
    // new_node->next = list.head;
    // list.head = new_node;
  }

  Node *p, *q;
  while (m--)
  {
    int count1 = 0, count2 = 0;
    scanf("%d%d", &x, &y);
    for (p = list.head; p != NULL; p = p->next)
    {
      count1++;
      if (count1 == n - x + 1)
        break;
    }
    for (q = list.head; q != NULL; q = q->next)
    {
      count2++;
      if (count2 == n - y + 1)
        break;
    }

    if (p->top != 0)
    {
      for (int i = p->top - 1; i >= 0; i--)
      {
        q->value[q->top++] = p->value[i];
        p->value[i] = 0;
      }
      p->top = 0;
    }
  }

  int count = 0, temp = n;
  for (p = list.head; p != NULL; p->next)
  {
    count++;
    if (count == temp)
    {
      if (p->top == 0)
        printf("0");
      else
      {
        for (int i = 0; i < p->top; i++)
          printf("%d ", p->value[i]);
      }
      printf("\n");
      temp--;
      count = 0;
      p = list.head;
    }
    if (temp == 0)
      break;
  }

  return 0;
}