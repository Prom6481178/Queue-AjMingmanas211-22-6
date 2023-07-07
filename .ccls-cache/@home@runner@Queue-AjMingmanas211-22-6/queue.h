#include "node.h"

class Queue {
  NodePtr headPtr, tailPtr;
  int size;

public:
  void enqueue(int, int);
  int dequeue();
  Queue();
  ~Queue(); // dequeue all
  NodePtr node() { return headPtr; }
  int getSize() { return size; }
};
Queue::Queue() {
  size = 0;
  headPtr = NULL;
  tailPtr = NULL;
}

Queue::~Queue() {
  int i;
  int n = size;
  // while(size>0)
  for (i = 0; i < n; i++)
    dequeue();
}
void Queue::enqueue(int x, int y) {
  NodePtr new_node = new NODE(x, y);
  if (new_node) {
    if (headPtr == NULL)
      headPtr = new_node;
    else
      tailPtr->set_next(new_node);
    tailPtr = new_node;
    ++size;
  }
}

int Queue::dequeue() {
  int value;
  NodePtr t;
  t = headPtr;
  if (t != NULL) {
    value = t->get_value();
    headPtr = headPtr->get_next();
    if (headPtr == NULL)
      tailPtr = NULL;
    delete t;
    --size;
    return value;
  } else {
    cout << "Queue is empty" << endl;
    return 0;
  }
  return -1;
}