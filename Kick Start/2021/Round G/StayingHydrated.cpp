#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t;

  cin >> t;
  for(int _=0; _<t; _++) {
    ll k, x1, y1, x2, y2, a=0, b=0, x=-1, y=-1;
    vector<pair<ll, bool>> xs;
    vector<pair<ll, bool>> ys;
    cin >> k;
    for(ll i=0; i<k; i++) {
      cin >> x1 >> y1 >> x2 >> y2;
      xs.push_back({x1, false});
      xs.push_back({x2, true});
      ys.push_back({y1, false});
      ys.push_back({y2, true});
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    a = k;
    b = 0;

    for(auto val: xs) {
      if(val.second) {
        b++;
      } else {
        a--;
      }

      x = val.first;

      if(a <= b) {
        break;
      }
    }

    a = k;
    b = 0;

    for(auto val: ys) {
      if(val.second) {
        b++;
      } else {
        a--;
      }

      y = val.first;

      if(a <= b) {
        break;
      }
    }

    cout << "Case #" << _+1 << ": " << x << " " << y << endl;
  }
}
