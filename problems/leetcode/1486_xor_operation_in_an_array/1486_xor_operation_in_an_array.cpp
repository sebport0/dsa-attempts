// https://leetcode.com/problems/xor-operation-in-an-array
#include <cassert>
#include <iostream>
#include <sys/types.h>

using namespace std;

class Solution {
public:
  int xorOperation(int n, int start) {
    int xor_accumulation = 0;
    for (int i = 0; i < n; i++) {
      xor_accumulation ^= numI(start, i);
    }
    return xor_accumulation;
  }

private:
  int numI(int start, int i) { return start + 2 * i; }
};

int main() {
  Solution s = Solution();
  cout << "-- n = 5, start = 0 --" << endl;
  int n = 5;
  int start = 0;
  int result = s.xorOperation(n, start);
  cout << result << endl;

  cout << "-- n = 4, start = 3 --" << endl;
  n = 4;
  start = 3;
  cout << s.xorOperation(n, start) << endl;

  return 0;
}
