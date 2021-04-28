#include "deque.h"
#include <stdlib.h>
#include <assert.h>

struct stack{
  struct deque *sta;
};

// stack_create() create a new empty stack
// effects: allocates memory (caller must call stack_destroy)
// time: O(1)
struct stack *stack_create(void){
  struct stack *s = malloc (sizeof(struct stack));
  s->sta = deque_create();
  assert(s);
  return s;
}

// stack_destroy(s) destroys the stack s and frees all memory
// effects: s is no longer valid
// time: O(n)
void stack_destroy(struct stack *s){
  assert(s);
  deque_destroy(s->sta);
  free(s);
}

// stack_is_empty(s) determines if s is empty
// time: O(1)
bool stack_is_empty(const struct stack *s){
  assert(s);
  bool emp = deque_is_empty(s->sta);
  return emp;
}

// stack_push(item, s) pushes item on to the stack s
// effects: modifies s
// time: O(1)
void stack_push(int item, struct stack *s){
  assert(s);
  deque_insert_front(item, s->sta);
}

// stack_top(s) returns the top of the stack s
// requires: s is not empty
// time: O(1)
int stack_top(const struct stack *s){
  assert(s);
  assert(stack_is_empty(s) == false);
  int front = deque_front(s->sta);
  return front;
}

// stack_pop(s) removes and returns the top of stack s
// requires: s is not empty
// effects: modifies s
// time: O(1)
int stack_pop(struct stack *s){
  assert(s);
  assert(stack_is_empty(s) == false);
  int front = deque_front(s->sta);
  deque_remove_front(s->sta);
  return front;
}
