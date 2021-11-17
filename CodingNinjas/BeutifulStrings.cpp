#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

using namespace std;

int main() {
  int n, l, f;
  set<int> v;
  string temp;
  cin >> n;
  cin >> l;
  cin >> f;
  for(int i=0; i<n; i++) {
    cin >> temp;
    int sb=0, l1=-1, r1=-1, l2=-1, r2=-1;
    for(int j=0; j<l; j++) {
      char c=temp[i];
      if(c == '1') {
        if(l1 == -1) {
          l1=j;
        } else if(l2 == -1) {
          l2=j;
        }
        r2=r1;
        r1=j;
        sb++;
      }
    }

    if(sb == 0) {
      v.insert(0);
      f++;
    } else if(sb == 1) {
      v.insert(0);
    } else if(sb == 2) {
      v.insert(1);
    } else {
      v.insert(min(l2-l1+1, r2-r1+1));
    }
  }

  int sum=0;
  int i=0;
  for(auto x: v) {
    if(i < f && i < n) {
      sum+=x;
    } else {
      break;
    }
    i++;
  }

  cout << sum << endl;

  return 0;
}
