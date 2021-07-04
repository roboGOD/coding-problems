#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

using namespace std;

int main() {
  lli t, n;
  string s;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n;
    cin >> s;
    lli result[n];
    result[0] = 1;

    cout << "Case #" << _+1 << ": 1 ";
    for(lli i=1; i<n; i++) {
      if(s[i-1] < s[i]) {
        result[i] = result[i-1] + 1;
      } else {
        result[i] = 1;
      }

      cout << result[i];

      if(i != n-1) {
        cout << " ";
      }
    }

    cout << endl;
  }
}
