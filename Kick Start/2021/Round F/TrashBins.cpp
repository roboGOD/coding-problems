#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t, n, sum;
  string s;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n;
    cin >> s;
    sum = 0;
    ll prev = -1;
    ll diff = 0, mid = 0;
    ll i = 0;
    for(i=0; i<n; i++) {
      char c = s[i];
      if(c == '1') {
        if(prev == -1) {
          sum += diff*(diff+1)/2;
        } else if(diff >= 1) {
          mid = diff/2;

          if(diff == 1) {
            sum += 1;
          } else if(diff % 2 == 0) {
            sum += mid*(mid+1);
          } else {
            sum += mid*(mid+1);
            sum += mid + 1;
          }
        }

        prev = i;
        diff = 0;
      } else {
        diff++;
      }
    }

    if(prev != i) {
      sum += diff*(diff+1)/2;
    }

    cout << "Case #" << _+1 << ": " << sum << endl;
  }
}
