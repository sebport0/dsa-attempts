// https://leetcode.com/problems/merge-two-sorted-lists
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
  // Helper function that brings the key idea to the problem.
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *mergedList = new ListNode();
    ListNode *tmpHead = mergedList;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        tmpHead->next = list1;
        list1 = list1->next;
      } else {
        tmpHead->next = list2;
        list2 = list2->next;
      }
      tmpHead = tmpHead->next;
    }
    if (list1 == nullptr) {
      tmpHead->next = list2;
    } else {
      tmpHead->next = list1;
    }
    return mergedList->next;
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // If I have an empty vector there are no nodes
    // to merge. Return nothing.
    if (lists.size() < 1) {
      return nullptr;
    }
    // Use lists as an accumulator of the merged lists.
    // Example:
    //  lists = [l_0, l_1, l_2, l_3, l_4]
    //  -> lists = [l_01, l_23, l_4]
    //  -> lists = [l_0123, l_4]
    //  -> lists = [l_01234]
    while (lists.size() > 1) {
      vector<ListNode *> mergedLists;
      for (int i = 0; i < lists.size(); i += 2) {
        ListNode *l1 = lists[0];
        // If l1 is the last list in the vector merge with a null, or
        // no node at all.
        ListNode *l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
        mergedLists.push_back(mergeTwoLists(l1, l2));
      }
      // At this point mergedLists contains the entire "pass"
      // through lists.
      lists = mergedLists;
    }
    // The final and only list in lists is the merge of all
    // the initial lists.
    return lists[0];
  }
};

int main(int argc, char *argv[]) {}
