// https://leetcode.com/problems/find-indices-of-stable-mountains
#include <cassert>
#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> stableMountains(vector<int> &height, int threshold) {
    vector<int> stables = {};
    for (int i = 1; i < height.size(); i++) {
      if (height[i - 1] > threshold) {
        stables.push_back(i);
      }
    }
    return stables;
  }
};

int main() {
  Solution s = Solution();

  vector<int> hs = {1, 2, 3, 4, 5};
  int threshold = 2;
  vector<int> out = s.stableMountains(hs, threshold);
  for (int x : out) {
    cout << x << " ";
  }
  cout << endl;

  hs = {10, 1, 10, 1, 10};
  threshold = 3;
  out = s.stableMountains(hs, threshold);
  for (int x : out) {
    cout << x << " ";
  }
  cout << endl;

  hs = {10, 1, 10, 1, 10};
  threshold = 10;
  out = s.stableMountains(hs, threshold);
  for (int x : out) {
    cout << x << " ";
  }
  cout << endl;

  hs = {11, 11, 11, 11, 11};
  threshold = 10;
  out = s.stableMountains(hs, threshold);
  for (int x : out) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
