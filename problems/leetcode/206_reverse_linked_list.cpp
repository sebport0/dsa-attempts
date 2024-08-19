
// https://leetcode.com/problems/reverse-linked-list/
#include <cassert>
#include <sys/types.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *previous = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
      ListNode *nextNode = current->next;
      current->next = previous;
      previous = current;
      current = nextNode;
    }
    return previous;
  }
};
