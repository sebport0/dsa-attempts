// https://leetcode.com/problems/count-houses-in-a-circular-street
#include <cassert>
#include <sys/types.h>

using namespace std;

class Solution {
public:
  int houseCount(Street *street, int k) {
    for (int i = 0; i < k; i++) {
      if (street->isDoorOpen())
        street->closeDoor();
      street->moveRight();
    }
    street->openDoor();
    int houses = 1;
    street->moveRight();
    while (!street->isDoorOpen()) {
      houses++;
      street->moveRight();
    }
    return houses;
  }
};

int main() { return 0; }
