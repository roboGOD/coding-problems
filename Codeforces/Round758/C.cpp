#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

void solve() {
  ll n,t, mxa=-1, ai, mxb=-1, bi;
  cin >> n;
  vector<ll> a, b, rs;
  for(ll i=0; i<n; i++) {
    cin >> t;
    if(mxa == -1 || mxa < t) {
      mxa = t;
      ai = i;
    }
    a.pb(t);
  }

  for(ll i=0; i<n; i++) {
    cin >> t;
    if(mxb == -1 || mxb < t) {
      mxb = t;
      bi = i;
    }
    b.pb(t);
  }

  for(ll i=0; i<n; i++) {
    if(a[i] >= min(a[ai], a[bi]) || b[i] >= min(b[ai], b[bi])) {
      rs.pb(1);
    } else {
      rs.pb(0);
    }
  }

  for(ll i=0; i<n; i++) {
    cout << rs[i];
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
