#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t;
  cin >> t;
  while(t--) {
    string s, keys;
    map<char, int> mp;
    ll n, cur=-1, rs=0, npos=0;
    cin >> keys;
    cin >> s;
    n = s.length();
    for(int i=0; i<26; i++) {
      mp.insert({keys[i], i+1});
    }

    if(n > 0) {
      cur=mp.at(s[0]);
      for(ll i=1; i<n; i++) {
        npos = mp.at(s[i]);
        // cout << cur << " " << npos << endl;
        rs += abs(cur-npos);
        cur = npos;
      }
    }
    cout << rs << endl;
  }
  return 0;
}
