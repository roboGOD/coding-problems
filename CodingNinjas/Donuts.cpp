#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main() {
  ll t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    vector<ll> v;
    for(ll i=0; i<n; i++) {
      ll temp;
      cin >> temp;
      v.pb(temp);
    }

    sort(v.begin(), v.end());
    ll sum=0;
    ll cc=0;
    ll tt=n/4;
    for(ll i=n-3; cc < tt; cc++, i-=3) {
      sum += v[i];
    }

    cout << sum << endl;
  }
  return 0;
}
