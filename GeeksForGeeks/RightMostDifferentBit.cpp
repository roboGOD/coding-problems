#include <iostream>
using namespace std;

int posOfRightMostDiffBit(int m, int n) {
  if(m == n) {
    return 0;
  }

  int mm = 0, mn = 0;
  int count = 0;
  int prevM = -1;
  int prevN = -1;

  while(mm == mn && (m != prevM || n != prevN)) {
    mm = m % 2;
    mn = n % 2;

    prevM = m;
    prevN = n;
    m = m / 2;
    n = n / 2;
    count++;
  }

  if((m == prevM || n == prevN) && mm == mn) {
    count++;
  } 

  return count;
}

int main() {
  int m, n;
  cin >> m >> n;

  cout << posOfRightMostDiffBit(m, n) << endl;
}
