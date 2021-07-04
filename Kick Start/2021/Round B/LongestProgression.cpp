#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

using namespace std;

int main() {
  lli t, n;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n;
    lli a[n];
    lli d[n-1];
    lli mx = 0;

    for(lli i =0; i< n; i++) {
      cin >> a[i];
    }

    for(lli i=0; i<n-1; i++) {
      d[i] = a[i+1] - a[i];
    }

    if(n <= 2) {
      mx = 2;
    } else {
      lli prev = -1;
      lli k = 0;
      lli start = 0;

      for(lli i=0; i<n-1; i++) {
        if(prev == -1) {
          k = 1;
          start = i;
          prev = d[i];
        } else if(prev == d[i]) {
          k++;
        } else if(prev != d[i]) {
          if(i == n-2 || d[i] + d[i+1] != 2*prev) {
            mx = max(k+2, mx);
          } else if(i == n-3 || (d[i] + d[i+1] == 2*prev && d[i+2] != prev)) {
            mx = max(k+3, mx);
          } else if(d[i] + d[i+1] == 2*prev && d[i+2] == prev) {
            lli nl = 0;
            lli j = i+2;
            while(j < n-1 && prev == d[j]) {
              j++;
            }

            mx = max(mx, k+j-i);
          }
        }
      }

      if(k == n-1) {
        mx = max(mx, k+1);
      }
    }

    cout << "Case #" << _+1 << ": " << mx << endl;
  }
}
