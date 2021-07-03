#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

using namespace std;

lli goodness(string s, lli n) {
  lli g = 0;
  for(lli i=0; i<n/2; i++) {
    if(s[i] != s[n-i-1]) {
      g++;
    }
  }
  
  return g;
}

int main() {
  lli t, n, k, g;
  string s;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n >> k;
    cin >> s;

    g = goodness(s, n);
    cout << "Case #" << _+1 << ": " << abs(k-g) << endl;
  }
  return 0;
}
