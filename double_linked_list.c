#include "double_linked_list.h"

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

// creates a new Node and returns pointer to it
static Node *NewNode(int data) {
  Node *new_node = (Node*) malloc(sizeof(Node));
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

Node *InsertAtHead(Node *head, int data) {
  Node* new_node = NewNode(data);
  if (head == NULL) {
    head = new_node;
    return head;
  }
  head->prev = new_node;
  new_node->next = head;
  head = new_node;
  puts("The element has been inserted at the head");
  return head;
}

Node *InsertAtTail(Node *head, int data) {
  Node *temp = head;
  Node *new_node = NewNode(data);
  if (head == NULL) {
    head = new_node;
    return head;
  }
  while (temp->next != NULL)
    temp = temp->next;  // Go To last Node

  temp->next = new_node;
  new_node->prev = temp;
  puts("The element has been inserted at the tail");
  return head;
}

Node *DeleteFirst(Node *head) {
  Node *del = head;

  if (head == NULL || del == NULL)
    return head;

  head = del->next;

  if (del->next != NULL)
    del->next->prev = del->prev;

  free(del);
  puts("The first element has been deleted");
  return head;
}

Node *DeleteLast(Node *head) {
  Node *del = head;
  // base case
  if (head == NULL || del == NULL)
    return head;

  if (head->next == NULL)
    head = del->next;

  while (del->next != NULL) {
    del = del->next;
  }
  if (del->prev != NULL)
    del->prev->next = del->next;

  free(del);
  puts("The last element has been deleted");
  return head;
}

Node *DeleteByIndex(Node *head, int index) {
  Node *del = head;
  int i = 1;
  // base case
  if (head == NULL || del == NULL || index < 1)
    return head;

  // if node to be deleted is head node
  if (index == 1) {
    head = del->next;
    free(del);
    return head;
  }
  for (i = 1; i < index; i++) {
    if (del->next == NULL)
      return head;
    del = del->next;
  }
  // change next only if node to be deleted is NOT the last node */
  if (del->next != NULL)
    del->next->prev = del->prev;
  // change prev only if node to be deleted is NOT the first node
  if (del->prev != NULL)
    del->prev->next = del->next;
  // finally, free the memory occupied by del
  free(del);
  return head;
}

Node *DeleteList(Node *head) {
  Node *current = head;
  Node *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  head = NULL;
  return head;
}

void Print(Node *head) {
  Node *temp = head;
  printf("Forward: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void ReversePrint(Node *head) {
  Node *temp = head;
  if (temp == NULL)
    return;  // empty list, exit
  // Going to last Node
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // traversing backward using prev pointer
  printf("Reverse: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}
