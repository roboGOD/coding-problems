#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

void solve() {
  ll n;
  // vector<ll> res;
  cin >> n;
  if(n == 1) {
    cout << 1;
    // res.push_back(n);
  } else {
    for(ll i=2; i<n+2; i++) {
      cout << i << " ";
      // res.push_back(i);
    }
  }

  cout << endl;
}

int main() {
  ll t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
