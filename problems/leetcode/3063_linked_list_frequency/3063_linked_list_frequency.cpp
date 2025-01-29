#include <array>
#include <cassert>
#include <iostream>
#include <sys/types.h>
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
  ListNode *frequenciesOfElements(ListNode *head) {
    array<int, 100000> freqs = {};
    while (head != nullptr) {
      // head->val - 1 as index to prevent buffer overflows.
      // freqs index starts at 0 and ends at 99999.
      freqs[head->val - 1] += 1;
      head = head->next;
    }
    ListNode *result = new ListNode();
    ListNode *result_head = result;
    for (int i = 0; i < freqs.size(); i++) {
      if (freqs[i] != 0) {
        // Easier to return the final result because first node
        // is there to "link" the rest of the nodes.
        // Doing:
        //  result->val = freqs[i]
        //  result->next = new ListNode();
        //  result = result->next;
        // Results in the final node with a 0 at the end.
        result->next = new ListNode(freqs[i]);
        result = result->next;
      }
    }
    return result_head->next;
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
  cout << " ]";
}

int main() {
  Solution s = Solution();
  // vector<int> v1 = {1, 1, 2, 1, 2, 3};
  // ListNode *l1 = s.frequenciesOfElements(makeListNode(v1));
  // printListNode(l1);
  vector<int> v2 = {3, 6, 3, 6, 8, 6};
  ListNode *l2 = s.frequenciesOfElements(makeListNode(v2));
  printListNode(l2);
  return 0;
}
