#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
  int data;
  struct LinkedList *link;
} LL;

LL *createLL()
{
  // variable decalrations
  int n, i, data;
  LL *head, *next, *temp;

  // Getting length of the list
  printf("Enter the number of nodes:");
  scanf("%d", &n);

  // Creating head node of the list
  head = (LL *)malloc(sizeof(LL));
  printf("Enter data of 0th node:");
  scanf("%d", &data);
  head->data = data;

  // Adding rest of the nodes
  next = head;
  for (i = 1; i < n; i++)
  {
    temp = (LL *)malloc(sizeof(LL));
    printf("Enter data of %dth node:", i);
    scanf("%d", &data);
    temp->data = data;
    next->link = temp;
    next = next->link;
  }
  next->link = NULL;
  printf("\n");

  return head;
}

void printLL(LL *head)
{
  LL *next = head;
  printf("Your list is: ");
  while (next)
  {
    printf("%d->", next->data);
    next = next->link;
  }
  printf("NULL\n\n");
}

int length(LL *head)
{
  LL *next = head;
  int count = 0;
  while (next)
  {
    count++;
    next = next->link;
  }
  return count;
}

LL *insert(LL *head, int data, int pos)
{
  LL *new = (LL *)malloc(sizeof(LL)), *next;
  new->data = data;
  if (pos == 0)
  {
    new->link = head;
    printf("Inserted %d\n\n", data);
    return new;
  }
  if (pos > length(head) + 1)
  {
    printf("Insertion failed: Invalid position given\n\n");
    free(new);
    return head;
  }
  else
  {
    next = head;
    for (int i = 1; i < pos; i++)
    {
      next = next->link;
    }
    new->link = next->link;
    next->link = new;
    printf("Inserted %d\n\n", data);
    return head;
  }
}

LL *delete(LL *head, int data, int pos)
{
}

int main()
{
  LL *head = createLL();
  printLL(head);
  head = insert(head, 99, 6);
  printLL(head);
  return 0;
}