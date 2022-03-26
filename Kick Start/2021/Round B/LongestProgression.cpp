#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

/*

5 5 4 5 5 5 4 5 6
0 -1 1 0 0 -1 1 1

*/


using namespace std;

int main() {
  lli t, n;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n;
    lli a[n];
    lli d[n-1];
    lli mx = 0;
    vector<pair<lli, lli>> chunks;

    for(lli i =0; i< n; i++) {
      cin >> a[i];
    }

    lli cl = 0;
    lli cval = -1;
    for(lli i=0; i<n-1; i++) {
      d[i] = a[i+1] - a[i];
      if(i == 0) {
        cval = d[i];
        cl = 1;
      } else if(cval == d[i]) {
        cl++;
      } else {
        chunks.push_back(pair(cval, cl));
        cval = d[i];
        cl = 1;
      }
    }

    chunks.push_back(pair(cval, cl));

    if(n <= 2) {
      mx = n;
    } else {
      lli prev;
      lli k = 0;
      lli i=0;

      while(i < n-1) {
        if(i == 0) {
          k = 1;
          prev = d[i];
        } else if(prev == d[i]) {
          k++;
          if(i == n-2) {
            mx = max(mx, k+1);
          }
        } else if(prev != d[i]) {
          if(i == n-2 || d[i] + d[i+1] != 2*prev) {
            mx = max(k+2, mx);
            prev = d[i];
            k = 1;
          } else if(i == n-3 || (d[i] + d[i+1] == 2*prev && d[i+2] != prev)) {
            mx = max(k+3, mx);
            prev = d[i];
            k = 1;
          } else if(d[i] + d[i+1] == 2*prev && d[i+2] == prev) {
            lli nl = 0;
            lli j = i+2;
            while(j < n-1 && prev == d[j]) {
              j++;
            }

            mx = max(mx, k+j-i+1);
            prev = d[i];
            k = 1;
          }
        }

        i++;
      }
    }

    cout << "Case #" << _+1 << ": " << mx << endl;
  }
}
