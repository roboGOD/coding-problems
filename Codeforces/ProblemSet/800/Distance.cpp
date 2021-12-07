#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

ld manhattanDistance(ll x1, ll y1, ll x2, ll y2) {
  return abs(x1-x2) + abs(y1-y2);
}

ld mdz(ll x, ll y) {
  return manhattanDistance(0, 0, x, y);
}

int main() {
  ll t, x, y, x1, y1;
  ld d, d1;
  bool found=false;
  cin >> t;
  while(t--) {
    found=false;
    cin >> x >> y;
    d = mdz(x, y)/2;
    for(x1=0; x1<=d; x1++) {
      y1=d-x1;
      d1 = manhattanDistance(x1, y1, x, y);
      if(d1 == d) {
        found=true;
        cout << x1 << " " << y1 << endl;
        break;
      }
    }
    if(!found) {
      cout << "-1 -1" << endl;
    }
  }
  return 0;
}
