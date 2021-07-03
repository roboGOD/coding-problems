#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

using namespace std;

int getCount(lli x, lli y) {
  return min(x/2, y) + min(x, y/2) - 2;
}

int main() {
  int t;
  lli r, c, total;

  cin >> t;
  for(int _=0; _<t; _++) {
    total = 0;
    cin >> r >> c;
    int mat[r][c];

    for(lli i = 0; i < r; i++) {
      for(lli j = 0; j < c; j++) {
        cin >> mat[i][j];
      }
    }

    int top[r][c];
    int left[r][c];
    int bottom[r][c];
    int right[r][c];

    for(lli i = 0; i < r; i++) {
      for(lli j = 0; j < c; j++) {
        if(mat[i][j] == 0) {
          top[i][j] = 0;
          left[i][j] = 0;
        } else {
          if(i == 0) {
            top[i][j] = 1;
          } else {
            top[i][j] = top[i-1][j] + 1; 
          }

          if(j == 0) {
            left[i][j] = 1;
          } else {
            left[i][j] = left[i][j-1] + 1;
          }
        }
      }
    }

    for(lli i = r-1; i >= 0; i--) {
      for(lli j = c-1; j >= 0; j--) {
        if(mat[i][j] == 0) {
          right[i][j] = 0;
          bottom[i][j] = 0;
        } else {
          if(i == r-1) {
            bottom[i][j] = 1;
          } else {
            bottom[i][j] = bottom[i+1][j] + 1;
          }

          if(j == c-1) {
            right[i][j] = 1;
          } else {
            right[i][j] = right[i][j+1] + 1;
          }
        }
      }
    }

    for(lli i = 0; i < r; i++) {
      for(lli j = 0; j < c; j++) {
        if(mat[i][j] != 0) {
          lli mt, ml, mb, mr;
          mt = top[i][j];
          ml = left[i][j];
          mb = bottom[i][j];
          mr = right[i][j];
          if(mt > 1) {
            if(ml > 1) {
              total += getCount(mt, ml);
            }

            if(mr > 1) {
              total += getCount(mt, mr);
            }
          }

          if(mb > 1) {
            if(ml > 1) {
              total += getCount(mb, ml);
            }

            if(mr > 1) {
              total += getCount(mb, mr);
            }
          }
        }
      }
    }

    cout << "Case #" << _+1 << ": " << total << endl;
  }
}
