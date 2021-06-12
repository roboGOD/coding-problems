#include <iostream>
#include <string>

using namespace std;

int editDistance(string s, string t) {
  int m = s.length();
  int n = t.length();

  int results[m][n];

  for(int i=m-1; i>=0; i--) {
    for(int j=n-1; j>=0; j--) { 
      if(i == m-1 || j == n-1) {
        if(s[i] == t[j]) {
          results[i][j] = m - 1 - i + n - 1 -j;
        } else if(i == m-1 && j == n-1) {
          results[i][j] = 1;
        } else if(i == m-1) {
          results[i][j] = 1 + results[i][j+1];
        } else if(j == n-1) {
          results[i][j] = 1 + results[i+1][j];
        }
      } else if(s[i] == t[j]) {
        results[i][j] = results[i+1][j+1];
      } else {
        results[i][j] = 1 + min(min(results[i+1][j], results[i][j+1]), results[i+1][j+1]);
      }
    }
  }

  return results[0][0];
}

int main() {
  string a, b;
  cin >> a >> b;

  cout << editDistance(a, b) << endl;

  return 1;
}
