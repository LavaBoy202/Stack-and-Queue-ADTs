#include "deque.h"
#include <stdlib.h>
#include <assert.h>

struct queue{
  struct deque *stac;
};

// queue_create() create a new empty queue
// effects: allocates memory (caller must call queue_destroy)
// time: O(1)
struct queue *queue_create(void){
  struct queue *q = malloc (sizeof(struct queue));
  q->stac = deque_create();
  return q;
}

// queue_destroy(q) destroys q and frees all memory
// effects: q is no longer valid
// time: O(n)
void queue_destroy(struct queue *q){
  assert(q);
  deque_destroy(q->stac);
  free(q);
}

// queue_is_empty(q) determines if q is empty
// time: O(1)
bool queue_is_empty(const struct queue *q){
  assert(q);
  bool emp = deque_is_empty(q->stac);
  return emp;
}

// queue_add_back(item, q) adds item to the back of q
// effects: modifies q
// time: O(1)
void queue_add_back(int item, struct queue *q){
  assert(q);
  deque_insert_back(item, q->stac);
}

// queue_front(q) returns the item at the front of q
// requires: q is not empty
// time: O(1)
int queue_front(const struct queue *q){
  assert(q);
  assert(queue_is_empty(q) == false);
  int front = deque_front(q->stac);
  return front;
}

// queue_remove_front(q) removes and returns the front of q
// requires: q is not empty
// effects: modifies q
// time: O(1)
int queue_remove_front(struct queue *q){
  assert(q);
  assert(queue_is_empty(q) == false);
  int front = deque_front(q->stac);
  deque_remove_front(q->stac);
  return front;
}
