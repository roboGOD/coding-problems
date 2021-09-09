#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

map<ll, ll> m;

void insertMap(ll key) {
  if(m.find(key) != m.end()) {
    m[key] = m[key]+1;
  } else {
    m[key] = 1;
  }
}

int main() {
  ll t, d, mx;
  ll a[3][3];
  ll total;

  cin >> t;
  for(int _=0; _<t; _++) {
    m.clear();
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        if(i == 1 && j == 1) {
          continue;
        }

        cin >> a[i][j];
      }
    }

    d = a[1][2] - a[1][0];
    if(d%2==0) {
      d = d/2;
      insertMap(a[1][0] + d);      
    }
    
    d = a[2][1] - a[0][1];
    if(d%2==0) {
      d = d/2;
      insertMap(a[0][1] + d);      
    }
    
    d = a[2][2] - a[0][0];
    if(d%2==0) {
      d = d/2;
      insertMap(a[0][0] + d);      
    }

    d = a[2][0] - a[0][2];
    if(d%2==0) {
      d = d/2;
      insertMap(a[0][2] + d);      
    }

    mx = 0;

    for(auto kv: m) {
      if(kv.second > mx) {
        d = kv.first;
        mx = kv.second;
      }
    }

    // cout << "D " << d << endl;

    a[1][1] = d;

    total = 0;

    for(ll i=0; i<3; i++) {
      d = a[i][1] - a[i][0];
      if(a[i][2] - a[i][0] == 2*d) {
        total++;
      }
    }

    for(ll i=0; i<3; i++) {
      d = a[1][i] - a[0][i];
      if(a[2][i] - a[0][i] == 2*d) {
        total++;
      }
    }

    if(a[2][2] - a[0][0] == 2*(a[1][1]-a[0][0])) {
      total++;      
    }

    if(a[2][0] - a[0][2] == 2*(a[1][1]-a[0][2])) {
      total++;      
    }

    cout << "Case #" << _+1 << ": " << total << endl;
  }
}
