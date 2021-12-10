#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t;

  cin >> t;
  for(int _=0; _<t; _++) {
    ll n, d, c, m;
    string s;
    bool rs = true;
    bool pl = true;
    cin >> n >> d >> c >> m;
    cin >> s;
    for(char ch: s) {
      if(ch == 'C') {
        if(pl) {
          if(c > 0) {
            c--;
          } else {
            pl = false;
          }
        }
      } else {
        if(pl) {
          if(d > 0) {
            d--;
            c += m;
          } else {
            pl = false;
            rs = false;
            break;
          }
        } else {
          rs = false;
          break;
        }
      }
    }
    cout << "Case #" << _+1 << ": " << (rs ? "YES" : "NO") << endl;
  }
}
