#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

int main() {
  ll t;


  cin >> t;
  for(ll _=0; _<t; _++) {
    ll d, n, k, s, e, h, max = 0;
    cin >> d >> n >> k;

    vector<vector<ll>> starts, ends;
    vector<ll> tracker, allt;
    
    for(ll i=0; i<=d; i++) {
      starts.push_back({});
      ends.push_back({});
    }

    for(ll i=0; i<n; i++) {
      cin >> h >> s >> e;
      
      starts[s-1].push_back(h);
      ends[e].push_back(h);
    }

    for(ll i=0; i<d; i++) {
      for(ll el: ends[i]) {
        auto it = find(tracker.begin(), tracker.end(), el);
        if(it != tracker.end()) {
          tracker.erase(it);
        } else {
          auto it = find(allt.begin(), allt.end(), el);
          if(it != allt.end()) {
            allt.erase(it);
          }
        }
      }

      if(tracker.size() < k && allt.size() > 0) {
        sort(allt.begin(), allt.end());
        while(tracker.size() < k && allt.size() > 0) {
          tracker.push_back(allt.back());
          allt.pop_back();
        }
      }

      ll ms = tracker.size();
      ll cs = starts[i].size();
      
      if(ms + cs <= k) {
        for(ll el: starts[i]) {
          tracker.push_back(el);
        }
      } else {
        sort(tracker.begin(), tracker.end(), greater<ll>());
        sort(starts[i].begin(), starts[i].end(), greater<ll>());
        vector<ll> tt(tracker);
        tracker.clear();

        ll j = 0;
        ll sindex = 0;
        ll tindex = 0;
        while(j < k) {
          if(tindex < ms && sindex < cs) {
            if(tt[tindex] >= starts[i][sindex]) {
              tracker.push_back(tt[tindex]);
              tindex++;
            } else {
              tracker.push_back(starts[i][sindex]);
              sindex++;
            }
          } else if(tindex < ms) {
            tracker.push_back(tt[tindex]);
            tindex++;
          } else if(sindex < cs) {
            tracker.push_back(starts[i][sindex]);
            sindex++; 
          }
          j++;
        }

        while(sindex < cs) {
          allt.push_back(starts[i][sindex]);
          sindex++;
        }

        while(tindex < ms) {
          allt.push_back(tt[tindex]);
          tindex++;
        }
      }

      ll tmax = 0;
      for(auto el: tracker) {
        tmax += el;
      }

      if(tmax > max) {
        max = tmax;
      }
    }

    cout << "Case #" << _+1 << ": " << max << endl;
  }
}
