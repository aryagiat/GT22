// linkedlist.cpp
#include <iostream>

struct Node{
  int option;
  Node * next;
  Node * prev;
};

// Function to build a doubly circular linked list forward for the options on the start.
void ListBuild(Node * &head, Node * &tail, int value){
  struct Node * p = new Node;
    p->option = value;
    p->next = head;
    p->prev = tail;
    if (head == NULL){
      head = p;
      tail = p;
    }
    else{
      tail->next = p;
      tail = p;
      head-> prev = tail;
    }
}
