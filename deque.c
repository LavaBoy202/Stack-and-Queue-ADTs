#include "deque.h"
#include <stdlib.h>
#include "cs136-trace.h"
#include <stdio.h>
#include <assert.h>

/////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THIS STRUCTURE
/////////////////////////////////////////////////////////////////////////////
struct llnode {
  int item;
  struct llnode *prev;
  struct llnode *next;
};

struct deque {
  struct llnode *front;
  struct llnode *back;
};
/////////////////////////////////////////////////////////////////////////////

struct list {
  struct llnode *front;
  struct llnode *back;
};
// The following applies to all functions
// requires: all deque parameters must be valid (non-null)
// time: (n) is the number of items in the deque

// deque_create() returns a pointer to a new (empty) deque
// effects: allocates memory (caller must call deque_destroy)
// time: O(1)
struct deque *deque_create(void){
  struct deque *deq = malloc(sizeof(struct deque));
  deq->front = NULL;
  deq->back = NULL;
  assert(deq);
  return deq;
}

// deque_destroy(deq) destroys the deq
// effects: deq is no longer valid (freed)
// time: O(n)
void deque_destroy(struct deque *deq){
  assert(deq);
  struct llnode *curnode = deq->front;
  struct llnode *nextnode = NULL;
  while (curnode) {
    nextnode = curnode->next;
    free(curnode);
    curnode = nextnode;
  }
  free(deq);
}

// deque_is_empty(deq) determines if deq is empty
// time: O(1)
bool deque_is_empty(const struct deque *deq){
  assert(deq);
  if (deq->front == NULL && deq->back == NULL) {
    return true;
  }
  return false;
}

// deque_insert_front(item, deq) inserts item into the front of deq
// effects: modifies deq
// time: O(1)
void deque_insert_front(int item, struct deque *deq){
  assert(deq);
  struct llnode *newnode = malloc(sizeof(struct llnode));
    newnode->item = item;
    newnode->next = deq->front;
    newnode->prev = NULL;
    deq->front = newnode;
  if (deq->back == NULL) {
    deq->back = newnode;
  }
}

// deque_front(deq) returns the front of deq
// requires: deq is not empty
// time: O(1)
int deque_front(const struct deque *deq){
  assert(deq);
  assert(deque_is_empty(deq) == false);
  return deq->front->item;
}

// deque_remove_front(deq) removes and returns the front of deq
// requires: deq is not empty
// effects: modifies deq
// time: O(1)
//Dont know about the free function
int deque_remove_front(struct deque *deq){
  assert(deq);
  assert(deq->front != NULL);
  struct llnode *before = deq->front;
  int num = before->item;
  if(deq->front == deq->back) {
    deq->back = NULL;
  }
  deq->front = deq->front->next;
  free(before);
  return num;
}

// deque_insert_back(item, deq) inserts item into the back of deq
// effects: modifies deq
// time: O(1)
void deque_insert_back(int item, struct deque *deq){
  assert(deq);
  struct llnode *newnode = malloc(sizeof(struct llnode));
  if (!(deq->back == NULL)) {
    struct llnode *before = deq->back;
    newnode->item = item;
    newnode->prev = deq->back;
    before->next = newnode;
    deq->back = newnode;
    deq->back->next = NULL;
  }
  else {
    newnode->item = item;
    newnode->prev = deq->back;
    deq->back = newnode;
    deq->back->next = NULL;
    deq->front = newnode;
  }
}

// deque_back(deq) returns the back of deq
// requires: deq is not empty
// time: O(1)
int deque_back(const struct deque *deq){
  assert(deq);
  assert(deque_is_empty(deq) == false);
  return deq->back->item;
}

// deque_remove_back(deq) removes and returns the back of deq
// requires: deq is not empty
// effects: modifies deq
// time: O(1)
int deque_remove_back(struct deque *deq){
  assert(deq);
  assert(deque_is_empty(deq) == false);
  struct llnode *before = deq->back;
  int num = before->item;
  if(deq->front == deq->back) {
    deq->front = NULL;
    deq->back = NULL;
  }
  else {
    deq->back = deq->back->prev;
    deq->back->next = NULL;
  }
  free(before);
  return num;
}

void list_print(struct llnode *front) {
  struct llnode *curnode = front;
  if (curnode == NULL) {
    printf("[empty]\n");
    return;
  }
  printf("[");
  while (curnode) {
    printf("%d", curnode->item);
    curnode = curnode->next;
    if (curnode) {
      printf(",");
    }
  }
  printf("]\n");
}

// deque_print(deq) prints out the items in deq
// notes: prints "[empty]\n" if deq is empty
//        prints "[%d]\n" if deq has a single item
//        prints "[%d,%d,...,%d]\n" otherwise
//               so if the deq from front->back is 8,6,7,5,3,0,9
//               prints "[8,6,7,5,3,0,9]\n"
// effects: produces output
// time: O(n)
void deque_print(const struct deque *deq){
  assert(deq);
  list_print(deq->front);
}
void list_print2(struct llnode *back) {
  struct llnode *curnode = back;
  if (curnode == NULL) {
    printf("[empty]\n");
    return;
  }
  printf("[");
  while (curnode) {
    printf("%d", curnode->item);
    curnode = curnode->prev;
    if (curnode) {
      printf(",");
    }
  }
  printf("]\n");
}
// deque_print_reverse(deq) prints out the items in deq in reverse
// notes: prints "[empty]\n" if deq is empty
//        prints "[%d]\n" if deq has a single item
//        prints "[%d,%d,...,%d]\n" otherwise
//               so if the deq from front->back is 8,6,7,5,3,0,9
//               prints "[9,0,3,5,7,6,8]\n"
// effects: produces output
// time: O(n)
void deque_print_reverse(const struct deque *deq){
  assert(deq);
  list_print2(deq->back);
}
