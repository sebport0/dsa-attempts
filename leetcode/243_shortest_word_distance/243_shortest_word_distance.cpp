// https://leetcode.com/problems/shortest-word-distance
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
  int shortestDistance(vector<string> &wordsDict, string word1, string word2) {
    // -1 cannot happen.
    int i_word1 = -1, i_word2 = -1;
    // distance != 0 always because word1 != word2.
    int distance = wordsDict.size() - 1;
    for (int i = 0; i < wordsDict.size(); i++) {
      if (wordsDict[i] == word1) {
        i_word1 = i;
      }
      if (wordsDict[i] == word2) {
        i_word2 = i;
      }
      if (i_word1 != -1 && i_word2 != -1 && abs(i_word2 - i_word1) < distance) {
        distance = abs(i_word2 - i_word1);
      }
    }
    return distance;
  }
};

int main() {
  Solution s = Solution();
  vector<string> v = {"practice", "makes", "perfect", "coding", "makes"};
  assert(s.shortestDistance(v, "coding", "practice") == 3);
  assert(s.shortestDistance(v, "makes", "coding") == 1);
  return 0;
}
