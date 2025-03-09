// https://leetcode.com/problems/implement-stack-using-queues/
#include <cassert>
#include <deque>
#include <iostream>
#include <sys/types.h>

using namespace std;

class MyStack {
  deque<int> queue = {};

public:
  MyStack() {}
  void push(int x) { queue.push_front(x); }
  int pop() {
    int x = queue.front();
    queue.pop_front();
    return x;
  }
  int top() {
    int x = queue.front();
    return x;
  }
  bool empty() { return queue.empty(); }
};

int main() {
  MyStack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  cout << "top=" << stack.top() << endl;
  cout << "pop=" << stack.pop() << endl;
  cout << "empty=" << stack.empty() << endl;
  cout << "pop=" << stack.pop() << endl;
  cout << "pop=" << stack.pop() << endl;
  cout << "empty?=" << stack.empty() << endl;

  return 1;
}
