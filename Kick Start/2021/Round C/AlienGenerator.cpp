#include <bits/stdc++.h>
#define lli unsigned long long int
#define pb push_back

using namespace std;

int main() {
  lli t, n, k;
  long double temp;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n;
    k = 0;
    temp = 0;

    for(long double i = 1; i<= n; i++) {
      temp = n/i;
      temp -= (i-1)/2;
      if(temp == (lli)temp && temp > 0) {
        k++;
        // cout << "TT " << temp << " " << i << endl;
      }

      if(temp < 0) {
        break;
      }
    }

    cout << "Case #" << _+1 << ": " << k << endl;
  }
}
