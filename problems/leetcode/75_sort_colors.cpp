// https://leetcode.com/problems/sort-colors
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    unordered_map<int, int> colorsCount;
    colorsCount[0] = 0;
    colorsCount[1] = 0;
    colorsCount[2] = 0;
    for (int x : nums) {
      colorsCount[x] += 1;
    }
    int color = 0;
    for (int i = 0; i < nums.size(); i++) {
      while (colorsCount[color] == 0) {
        color++;
      }
      nums[i] = color;
      colorsCount[color]--;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{2, 0, 2, 1, 1, 0};
  s.sortColors(nums);
  for (int n : nums) {
    cout << n << endl;
  }

  return 0;
}
