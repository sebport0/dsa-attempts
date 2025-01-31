// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <sys/types.h>
#include <unordered_map>
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *curr = head;
    while (curr && curr->next) {
      if (curr->val == curr->next->val) {
        ListNode *to_delete = curr->next;
        curr->next = curr->next->next;
        delete to_delete;
      } else {
        curr = curr->next;
      }
    }
    return head;
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

int main() {
  Solution s = Solution();

  cout << "== [1, 1, 2] ==" << endl;
  vector<int> v = {1, 1, 2};
  ListNode *ll = makeListNode(v);
  ListNode *out = s.deleteDuplicates(ll);
  printListNode(out);

  cout << "== [1, 1, 2, 3, 3] ==" << endl;
  v = {1, 1, 2, 3, 3};
  ll = makeListNode(v);
  printListNode(s.deleteDuplicates(ll));

  cout << "== [1, 1, 1, 1, 1] ==" << endl;
  v = {1, 1, 1, 1, 1};
  ll = makeListNode(v);
  printListNode(s.deleteDuplicates(ll));

  return 0;
}
