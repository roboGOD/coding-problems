#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main() {
  ll t, n, l, r, k, temp, sum;
  cin >> t;
  while(t--) {
    cin >> n >> l >> r >> k;
    vector<ll> arr;
    for(ll i=0; i<n; i++) {
      cin >> temp;
      arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    temp = 0;
    sum = 0;
    for(ll item: arr) {
      if(item >= l && item <= r) {
        sum += item;
        if(sum <= k) {
          temp++;
        } else {
          break;
        }
      }
    }
    cout << temp << endl;
  }
  return 0;
}
