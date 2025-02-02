// https://leetcode.com/problems/contains-duplicate
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sys/types.h>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (uint i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        return true;
      }
    }
    return false;
  }

  bool containsDuplicateSet(vector<int> &nums) {
    set<int> known_nums = {};
    for (int i = 0; i < nums.size(); i++) {
      if (known_nums.find(nums[i]) != known_nums.end()) {
        return true;
      }
      known_nums.insert(nums[i]);
    }
    return false;
  }
};

int main() {
  Solution s = Solution();

  return 0;
}
