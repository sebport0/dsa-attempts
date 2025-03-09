// https://leetcode.com/problems/climbing-stairs
#include <iostream>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    // Fibonnaci! Recursive solution timeouts in Leetcode.
    int prev = 0;
    int curr = 1;
    int result = 0;
    while (n > 0) {
      result = prev + curr;
      prev = curr;
      curr = result;
      n--;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int n = 1;
  cout << "n=" << n << "->" << s.climbStairs(n) << endl;
  n = 2;
  cout << "n=" << n << "->" << s.climbStairs(n) << endl;
  n = 3;
  cout << "n=" << n << "->" << s.climbStairs(n) << endl;
  n = 4;
  cout << "n=" << n << "->" << s.climbStairs(n) << endl;
  return 0;
}
