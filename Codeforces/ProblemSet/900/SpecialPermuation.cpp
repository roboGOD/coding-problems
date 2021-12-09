#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

// 1 2 3 4 5 6
// 2 => 
// 5 => 

void solve() {
  ll n, a, b, c;
  vector<ll> rs;
  cin >> n >> a >> b;
  if(!(n-a >= n/2-1+(a < b ? 1 : 0) && b >= n/2 + (a < b ? 1 : 0))) {
    rs.pb(-1);
  } else {
    c=0;
    c++;
    rs.pb(a);
    ll j=n;
    while(c < n/2) {
      if(j != a && j != b) {
        c++;
        rs.pb(j);
      }
      j--;
    }
    c++;
    rs.pb(b);
    j=1;
    while(c < n) {
      if(j != a && j != b) {
        rs.pb(j);
        c++;
      }
      j++;
    }
  }

  for(ll i: rs) {
    cout << i << " ";
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
