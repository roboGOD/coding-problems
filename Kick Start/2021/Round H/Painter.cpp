#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t;

  cin >> t;
  for(int _=0; _<t; _++) {
    ll n;
    string s;
    cin >> n;
    cin >> s;
    unordered_set<char> ps;
    ll count=0;
    for(char &c: s) {
      if(c == 'R' || c == 'Y' || c == 'B') {
        if(ps.find(c) == ps.end()) {
          count++;
        }

        ps.clear();
        ps.insert(c);
      } else if(c == 'O') {
        if(ps.find('R') == ps.end()) {
          count++;
        }

        if(ps.find('Y') == ps.end()) {
          count++;
        }

        ps.clear();
        ps = {'R', 'Y'};
      } else if(c == 'P') {
        if(ps.find('R') == ps.end()) {
          count++;
        }

        if(ps.find('B') == ps.end()) {
          count++;
        }

        ps.clear();
        ps = {'R', 'B'};
      } else if(c == 'G') {
        if(ps.find('Y') == ps.end()) {
          count++;
        }

        if(ps.find('B') == ps.end()) {
          count++;
        }

        ps.clear();
        ps = {'Y', 'B'};
      } else if(c == 'A') {
        if(ps.find('Y') == ps.end()) {
          count++;
        }

        if(ps.find('B') == ps.end()) {
          count++;
        }

        if(ps.find('R') == ps.end()) {
          count++;
        }

        ps.clear();
        ps = {'R', 'Y', 'B'};
      } else {
        ps.clear();
      }
    }

    cout << "Case #" << _+1 << ": " << count << endl;
  }
}
