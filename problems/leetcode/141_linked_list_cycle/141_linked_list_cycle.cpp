// https://leetcode.com/problems/linked-list-cycle
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <sys/types.h>
#include <unordered_set>
#include <utility>
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
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> known_nodes = {};
    ListNode *curr = head;
    while (curr != nullptr) {
      pair insert_result = known_nodes.insert(curr);
      // set.insert() returns a pair where the second
      // value is a boolean indicating if the value
      // was inserted or not.
      if (!insert_result.second) {
        return true;
      }
      curr = curr->next;
    }
    return false;
  }

  bool FloydHasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
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
