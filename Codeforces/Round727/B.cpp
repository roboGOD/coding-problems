#include <bits/stdc++.h>
#define lli long long int
using namespace std;


int main() {

  lli n, q;
  lli l, r;
  string s;
  cin >> n >> q;
  cin >> s;
  lli sum[n+1];

  sum[0] = 0;
  for(lli i=0; i<n; i++) {
    int c = s[i] - 96;
    sum[i+1] = c;
    
    sum[i+1] += sum[i];
  }
  
  while(q--) {
    cin >> l >> r;

    cout << sum[r] - sum[l-1] << endl;
  }

  return 0;
}
