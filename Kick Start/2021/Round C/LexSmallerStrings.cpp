#include <bits/stdc++.h>
#define lli unsigned long long int
#define pb push_back

using namespace std;

lli mod = 1'000'000'007;

lli modpow(lli x, lli e) {
	if (e == 0) return 1;
	lli a = modpow(x, e >> 1);
	a = a * a % mod;
	if (e & 1) a = a * x % mod;
	return a;
}

int main() {
  lli t, n, k, tt = 0, m;
  string s;

  cin >> t;
  for(int _=0; _<t; _++) {
    cin >> n >> k;
    cin >> s;
    tt = 0;
    m = n/2;
    if(n % 2 == 1) {
      m++;
    }

    for(lli i=0; i<m; i++) {
      if(s[i] == 'a') {
        continue;
      } else {
        tt += (s[i] - 'a') * modpow(k, m-i-1) % mod; 
      }
    }

    string subs = s.substr(0, n % 2 == 1 ? m-1 : m);
    reverse(subs.begin(), subs.end());

    if(n > 1 && subs < s.substr(m, n-1)) {
      tt++;
    }

    // cout << "REV " << subs << " " << s.substr(m, n-1) << endl;

    cout << "Case #" << _+1 << ": " << tt % mod << endl;
  }
}
