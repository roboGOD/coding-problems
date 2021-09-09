#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t, n ,c, total, mx, mr;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n >> c;
    ll a[n][2];
    mr = 0;

    for(ll i=0; i<n; i++) {
      cin >> a[i][0] >> a[i][1];
      mr = max(a[i][1], mr);
    }

    vector<ll> b;

    for(ll i=0; i<=mr; i++) {
      b.push_back(0);
    }

    for(ll i=0; i<n; i++) {
      ll lower = a[i][0];
      ll upper = a[i][1];
      for(ll j=lower+1; j<upper; j++) {
        b[j]++;
      }
    }

    sort(b.begin(), b.end(), greater<ll>());

    ll i =0;
    total = 0;

    while(i <= c && i <= mr) {
      // cout << b[i] << " ";
      total += b[i];
      i++;
    }

    cout << endl;

    cout << "Case #" << _+1 << ": " << total + n << endl;
  }
}
