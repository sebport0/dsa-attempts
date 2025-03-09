// https://leetcode.com/problems/bitwise-or-of-adjacent-elements/description/
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sys/types.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> orArray(vector<int> &nums) {
    vector<int> ans = {};
    for (int i = 0; i < nums.size() - 1; i++) {
      ans.push_back(nums[i] | nums[i + 1]);
    }
    return ans;
  }
};

int main() { return 0; }
