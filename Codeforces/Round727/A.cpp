#include <bits/stdc++.h>
#define lli long long int
using namespace std;


int main() {

  lli k, n, x, t;
  lli sum, mx, tp, diff;
  lli tx;
  cin >> k;
  while(k--) {
    cin >> n >> x >> t;
    sum = 0;

    tx = t/x;    
    diff = n - tx;
    sum = diff * tx;
    sum += (n-1)*tx + tx*(2*(-tx) + tx-1)/2;

    cout << sum << endl;
  }

  return 0;
}
