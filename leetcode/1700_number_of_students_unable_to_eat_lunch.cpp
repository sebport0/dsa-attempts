// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description
#include <cassert>
#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;

class Solution {

public:
  // Remember that the amount of students and sandwiches is the same.
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    // Count students preferences.
    int Ncircular = 0;
    int Nsquare = 0;
    int studentsLeft = students.size();
    for (int s : students) {
      if (s == 0) {
        Ncircular++;
      } else {
        Nsquare++;
      }
    }
    for (int s : sandwiches) {
      if (s == 0) {
        if (Ncircular != 0) {
          Ncircular--;
          studentsLeft--;
        } else {
          // No student is willing to eat the sandwich.
          return studentsLeft;
        }
      } else {
        if (Nsquare != 0) {
          Nsquare--;
          studentsLeft--;
        } else {
          // No student is willing to eat the sandwich.
          return studentsLeft;
        }
      }
    }
    return studentsLeft;
  }
};

int main() {
  Solution sol;
  vector<int> st{1, 1, 0, 0};
  vector<int> sw{0, 1, 0, 1};
  assert(sol.countStudents(st, sw) == 0);
  st.clear();
  st = {1, 1, 1, 0, 0, 1};
  sw.clear();
  sw = {1, 0, 0, 0, 1, 1};
  int r = sol.countStudents(st, sw);
  cout << r << endl;
  return 1;
}
