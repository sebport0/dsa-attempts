// https://leetcode.com/problems/number-of-good-pairs
#include <algorithm>
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
  int numIdenticalPairs(vector<int> &nums) {
    int good_pairs = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] == nums[j]) {
          good_pairs++;
        }
      }
    }
    return good_pairs;
  }

  int numIdenticalPairsHashMap(vector<int> &nums) {
    int good_pairs = 0;
    unordered_map<int, int> seen = {};
    for (auto num : nums) {
      good_pairs += seen[num];
      seen[num]++;
    }
    return good_pairs;
  }
};

int main() {
  Solution s = Solution();

  return 0;
}
