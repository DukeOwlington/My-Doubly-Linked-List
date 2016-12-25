#ifndef H_DOUBLE_LINKED_LIST
#define H_DOUBLE_LINKED_LIST

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

Node *InsertAtHead(Node *head, int data);
Node *InsertAtTail(Node *head, int data);
Node *DeleteFirst(Node *head);
Node *DeleteLast(Node *head);
Node *DeleteByIndex(Node *head, int data);
Node *DeleteList(Node *head);
void Print(Node *head);
void ReversePrint(Node *head);

#endif
