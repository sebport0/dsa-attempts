// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
#include <cassert>
#include <iostream>
#include <sys/types.h>
#include <unordered_set>
#include <vector>

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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curr_a = headA;
    ListNode *curr_b = headB;
    unordered_set<ListNode *> seen_nodes = {};
    while (curr_a != nullptr || curr_b != nullptr) {
      // There are no cycles in the entire linked structure.
      if (curr_a != nullptr) {
        if (seen_nodes.find(curr_a) != seen_nodes.end()) {
          return curr_a;
        } else {
          seen_nodes.insert(curr_a);
          curr_a = curr_a->next;
        }
      }
      if (curr_b != nullptr) {
        if (seen_nodes.find(curr_b) != seen_nodes.end()) {
          return curr_b;
        } else {
          seen_nodes.insert(curr_b);
          curr_b = curr_b->next;
        }
      }
    }
    return nullptr;
  }
};

ListNode *makeListNode(vector<int> v) {
  ListNode *curr = new ListNode();
  ListNode *head = curr;
  for (int i = 0; i < v.size(); i++) {
    curr->val = v[i];
    if (i + 1 < v.size() && v[i + 1] != 0) {
      curr->next = new ListNode();
      curr = curr->next;
    }
  }
  return head;
}

void printListNode(ListNode *list) {
  cout << "[";
  while (list != nullptr) {
    cout << " " << list->val;
    list = list->next;
  }
  cout << " ]" << endl;
}

int main() { return 0; }
