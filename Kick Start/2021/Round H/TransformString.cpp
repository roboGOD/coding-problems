#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t;

  cin >> t;
  for(int _=0; _<t; _++) {
    string s, f;
    cin >> s;
    cin >> f;

    ll diff=0, td=0, tb=0, result=0;

    for(int c: s) {
      diff=0;
      for(int i=0; i<f.length(); i++) {
        int d = f[i];
        td = abs(c-d);
        tb = 26-td;
        td = min(td, tb);

        if(i == 0 || diff > td) {
          diff = td;
        }
      }

      result += diff;
    }
    
    cout << "Case #" << _+1 << ": " << result << endl;
  }
}
