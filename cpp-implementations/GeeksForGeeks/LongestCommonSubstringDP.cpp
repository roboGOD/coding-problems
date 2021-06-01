#include <iostream>
#include <string>
#define lli long long int
using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m) {
  int count = 0;
  string X1, X2;
  int x1, x2;
  if(n > m) {
    X1 = S1;
    X2 = S2;
    x1 = n;
    x2 = m;
  } else {
    X1 = S2;
    X2 = S1;
    x1 = m;
    x2 = n;
  }
  int lcsuffixPrev[x2 + 1];
  int lcsuffixNext[x2 + 1];

  for(int i=0; i <= x1; i++) {
    for(int j=0; j <= x2; j++) {
      if(i == 0 || j == 0) {
        lcsuffixNext[j] = 0;
      } else if(X1[i-1] == X2[j-1]) {
        lcsuffixNext[j] = lcsuffixPrev[j-1] + 1;
        count = max(lcsuffixNext[j], count);
      } else {
        lcsuffixNext[j] = 0;
      }
    }

    for(int j=0; j<=x2; j++) {
      lcsuffixPrev[j] = lcsuffixNext[j];
      lcsuffixNext[j] = 0;
    }
  }

  return count;
}

int main() {

  string X1;
  string X2;
  int x1;
  int x2;

  cin >> x1 >> x2 >> X1 >> X2;
  cout << longestCommonSubstr(X1, X2, x1, x2) << endl;
  return 0;
}
