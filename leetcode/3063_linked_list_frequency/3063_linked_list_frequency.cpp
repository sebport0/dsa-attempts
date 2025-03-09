#include <array>
#include <cassert>
#include <iostream>
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

  // V2: use a hash map instead of an array to
  // count the frequencies.
  ListNode *frequenciesOfElementsV2(ListNode *head) {
    // freqs<node values, appeareances count>
    unordered_map<int, int> freqs = {};
    while (head != nullptr) {
      freqs[head->val] += 1;
      head = head->next;
    }
    ListNode *result = new ListNode();
    ListNode *curr = result;
    for (pair<const int, int> &item : freqs) {
      curr->next = new ListNode(item.second);
      curr = curr->next;
    }
    return result->next;
  }

  // V3: use a hash map but instead of doing a double pass:
  //   1. Original linked list.
  //   2. Hash map with frequencies.
  // Do it in one pass of the original linked list.
  ListNode *frequenciesOfElementsV3(ListNode *head) {
    unordered_map<int, ListNode *> freqs;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      // If curr ListNode doesn't exists in hash map.
      if (freqs.find(curr->val) == freqs.end()) {
        ListNode *newFreq = new ListNode(1, prev);
        freqs[curr->val] = newFreq;
        prev = newFreq;
      } else {
        freqs[curr->val]->val += 1;
      }
      curr = curr->next;
    }
    return prev;
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
  cout << "== Using array == " << endl;
  vector<int> v1 = {1, 1, 2, 1, 2, 3};
  ListNode *l1 = s.frequenciesOfElements(makeListNode(v1));
  printListNode(l1);
  vector<int> v2 = {3, 6, 3, 6, 8, 6};
  ListNode *l2 = s.frequenciesOfElements(makeListNode(v2));
  printListNode(l2);
  cout << endl;

  cout << "== Using unordered hash map == " << endl;
  vector<int> v = {1, 1, 2, 1, 2, 3};
  ListNode *l3 = s.frequenciesOfElementsV2(makeListNode(v));
  printListNode(l3);
  v = {3, 6, 3, 6, 8, 6};
  ListNode *l4 = s.frequenciesOfElements(makeListNode(v));
  printListNode(l4);
  cout << endl;

  cout << "== Using unordered hash map with one iterarion == " << endl;
  v = {1, 1, 2, 1, 2, 3};
  ListNode *l5 = s.frequenciesOfElementsV3(makeListNode(v));
  printListNode(l5);
  v = {3, 6, 3, 6, 8, 6};
  ListNode *l6 = s.frequenciesOfElements(makeListNode(v));
  printListNode(l6);
  cout << endl;

  return 0;
}
