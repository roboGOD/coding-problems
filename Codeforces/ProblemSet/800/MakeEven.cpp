#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t;
  cin >> t;
  while(t--) {
    ll n, m;
    bool firstEven=false, hasEven=false;
    vector<int> a;
    cin >> n;
    if(n % 2 == 0) {
      cout << 0 << endl;
    } else {
      m = n;
      while(m > 0) {
        a.pb(m%10);
        if(a[a.size()-1]%2 == 0) {
          hasEven=true;
        }
        m = m/10;
      }
      if(a[a.size()-1]%2 == 0) {
        firstEven=true;
      }
      if(firstEven) {
        cout << 1 << endl;
      } else if(hasEven) {
        cout << 2 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
