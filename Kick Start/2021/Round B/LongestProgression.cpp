#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

using namespace std;

struct node {
  lli s1;
  lli s2;
  lli l1;
  lli l2;
  lli d1;
  lli d2;

  node(lli s1, lli l1, lli d1, lli s2, lli l2, lli d2): s1(s1), s2(s2), l1(l1), l2(l2), d1(d1), d2(d2) {
  }

  node(lli s1, lli l1, lli d1): s1(s1), s2(-1), l1(l1), l2(-1), d1(d1), d2(-1) {
  }
};

int main() {
  lli t, n;
  vector<node> v;

  cin >> t;
  for(int _=0; _<t; _++) {
    v.clear();

    cin >> n;
    lli a[n];

    for(lli i =0; i< n; i++) {
      cin >> a[i];
    }

    lli start = -1;
    lli diff = -1;
    bool isf = true;
    lli i = 0;

    while(i < n) {
      if(isf) {
        start = i;
        isf = false;

        if(i == n-1) {
          v.pb(node(start, 1, -1));
        } else {
          diff = a[i+1] - a[i];
        }

        i++;
      } else {
        if(i == n-1) {
          v.pb(node(start, i-start+1, diff));
          i++;
        } else if(a[i+1] - a[i] != diff) {
          v.pb(node(start, i-start+1, diff));
          isf = true;
          start = -1;
          diff = -1;
        } else {
          i++;
        }
      }
    }

    lli mx = 0;

    for(lli i=0; i<v.size(); i++) {
      mx = max(mx, v[i].l1);
      lli j = i+1;
      lli il = v[i].s1 + v[i].l1 - 1;

      // cout << "VI " << v[i].s1 << " " << il << endl; 
      bool found = false;
      bool sf = false;

      while(j < v.size()) {
        if(v[j].s1 - il == 2 && a[v[j].s1] - a[il] == 2*v[i].d1) {
          if(v[j].d1 == v[i].d1) {
            found = true;
            break;
          } else {
            sf = true;
            break;
          }
        }
        j++;
      }
      
      if(j < v.size() && found) {
        // cout << "VI " << v[i].s1 << " " << il << endl; 
        // cout << "VJ " << v[j].s1 << " " << v[j].s1 + v[j].l1 - 1 << endl; 
        mx = max(v[i].l1 + v[j].l1 + 1, mx);
      } else if(j < v.size() && sf) {
        mx = max(v[i].l1 + 2, mx);
      } else {
        if(il == n-1) {
          mx = max(v[i].l1, mx);
        } else {
          mx = max(v[i].l1+1, mx);
        }
      }
    }

    cout << "Case #" << _+1 << ": " << mx << endl;
  }
}
