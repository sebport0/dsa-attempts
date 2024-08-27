// https://leetcode.com/problems/merge-two-sorted-lists
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
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
};

int main(int argc, char *argv[]) {}
