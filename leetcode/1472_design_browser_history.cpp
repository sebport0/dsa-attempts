// https://leetcode.com/problems/design-browser-history/description
#include <cassert>
#include <string>
#include <sys/types.h>
#include <vector>

using namespace std;

/*
 Container: vector.
 Space complexity: O(n), since we have n possible urls in the history.
 Time complexity:
  - O(1) for all operations.
*/
class BrowserHistory {
  vector<string> history;
  int current = 0;

public:
  BrowserHistory(string homepage) { history.push_back(homepage); }

  void visit(string url) {
    // Current pointer must always increase because we are "inserting"
    // one more page in the history, either at the end or somewhere
    // in between.
    current += 1;
    if (current > history.size() - 1) {
      history.push_back(url);
    } else {
      history[current] = url;
      // Forget about the pages that comes next. They are no longer
      // valid in the history.
      history.resize(current + 1);
    }
  }

  string back(int steps) {
    // Go back N steps from current.
    current -= steps;
    // But no so far.
    if (current < 0)
      current = 0;
    return history[current];
  }

  string forward(int steps) {
    current += steps;
    if (current > history.size() - 1)
      current = history.size() - 1;
    return history[current];
  }

  string at() { return history[current]; }
};

int main() {
  BrowserHistory bhist{"leetcode.com"};
  assert(bhist.at() == "leetcode.com");
  bhist.visit("google.com");
  assert(bhist.at() == "google.com");
  bhist.visit("somenews.com");
  assert(bhist.at() == "somenews.com");
  bhist.back(1);
  assert(bhist.at() == "google.com");
  bhist.back(1);
  assert(bhist.at() == "leetcode.com");
  bhist.forward(1);
  assert(bhist.at() == "google.com");
  bhist.forward(5);
  assert(bhist.at() == "somenews.com");
  bhist.back(10);
  assert(bhist.at() == "leetcode.com");
  bhist.visit("instagram.com");
  assert(bhist.at() == "instagram.com");
  bhist.forward(2);
  assert(bhist.at() == "instagram.com");
  return 1;
}
