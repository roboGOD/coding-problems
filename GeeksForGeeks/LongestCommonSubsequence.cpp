#include <iostream>
#include <string>

using namespace std;

/**
 * 
 * Longest Common Subsequence DP
 * Test Case: 
 * 
 * 13 8
 * MICHAELANGELO
 * PHXELULO
 * 
 **/
int longestCommonSubsequence(int m, int n, string x, string y) {
  int results[m+1][n+1];

  for(int i=m; i>=0; i--) {
    for(int j=n; j>=0; j--) { 
      if(i == m || j == n) {
        results[i][j] = 0;
      } else if(x[i] == y[j]) {
        results[i][j] = 1 + results[i+1][j+1];
      } else {
        results[i][j] = max(results[i+1][j], results[i][j+1]);
      }
    }
  }

  return results[0][0];
}

int main() {
  int m,n;
  cin >> m >> n;
  string a, b;
  cin >> a >> b;

  cout << longestCommonSubsequence(m, n, a, b) << endl;

  return 1;
}
