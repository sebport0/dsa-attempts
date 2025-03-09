// https://leetcode.com/problems/intersection-of-two-arrays
#include <algorithm>
#include <cassert>
#include <set>
#include <sys/types.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> shorter = {};
    vector<int> larger = {};
    if (nums1.size() >= nums2.size()) {
      larger = nums1;
      shorter = nums2;
    } else {
      larger = nums2;
      shorter = nums1;
    }
    vector<int> intersection = {};
    sort(larger.begin(), larger.end());
    // To keep intersection sorted.
    sort(shorter.begin(), shorter.end());
    for (auto x : shorter) {
      if (!binary_search(intersection.begin(), intersection.end(), x) &&
          binary_search(larger.begin(), larger.end(), x)) {
        intersection.push_back(x);
      }
    }
    return intersection;
  }

  vector<int> intersectionTwoSets(vector<int> &nums1, vector<int> &nums2) {
    set<int> nums1_set(nums1.begin(), nums1.end());
    set<int> nums2_set(nums2.begin(), nums2.end());
    set<int> larger = {};
    set<int> shorter = {};
    vector<int> intersection = {};
    if (nums1_set.size() > nums2_set.size()) {
      shorter = nums2_set;
      larger = nums1_set;
    } else {
      shorter = nums1_set;
      larger = nums2_set;
    }
    for (auto x : shorter) {
      if (find(intersection.begin(), intersection.end(), x) ==
              intersection.end() &&
          larger.find(x) != larger.end()) {
        intersection.push_back(x);
      }
    }
    return intersection;
  }
};

int main() {
  Solution s = Solution();

  return 0;
}
