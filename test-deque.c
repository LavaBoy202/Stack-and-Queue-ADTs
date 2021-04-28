#include <assert.h>
#include "deque.h"

int main(void) {
  struct deque *deq = deque_create();
  deque_print_reverse(deq); /* [empty] */
  deque_insert_front(1, deq);
  assert(deque_front(deq) == 1);
  assert(deque_back(deq) == 1);
  deque_print_reverse(deq);
  deque_print(deq);
  deque_insert_back(9, deq);
  deque_print(deq); //[1,9]
  deque_print_reverse(deq);
  assert(deque_remove_front(deq) == 1);
  assert(deque_remove_back(deq) == 9);
  assert(deque_is_empty(deq));
  deque_destroy(deq);
}
