// https://leetcode.com/problems/dot-product-of-two-sparse-vectors
#include <algorithm>
#include <cassert>
#include <sys/types.h>
#include <unordered_map>
#include <vector>

using namespace std;

class HashSparseVector {

public:
  unordered_map<int, int> non_zeros = {};
  HashSparseVector(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        non_zeros[i] = nums[i];
      }
    }
  }
  int dotProduct(HashSparseVector &vec) {
    int result = 0;
    for (auto i = non_zeros.begin(); i != non_zeros.end(); ++i) {
      if (vec.non_zeros.count(i->first) != 0) {
        result += i->second * vec.non_zeros[i->first];
      }
    }
    return result;
  }
};

class SlowSparseVector {
public:
  vector<int> ns;
  SlowSparseVector(vector<int> &nums) { ns = nums; }
  int dotProduct(SlowSparseVector &vec) {
    int result = 0;
    for (int i = 0; i < vec.ns.size(); i++) {
      result += ns[i] * vec.ns[i];
    }
    return result;
  }
};

int main() { return 0; }
