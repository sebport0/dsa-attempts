// https://leetcode.com/problems/single-number/
#include <cassert>
#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); i++) {
      num ^= nums[i];
    }
    return num;
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums = {2, 2, 1};
  cout << s.singleNumber(nums) << endl;

  nums = {4, 1, 2, 1, 2};
  cout << s.singleNumber(nums) << endl;
  return 0;
}
