#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxUniqueSplitHelper(string& s, int i, int n, unordered_set<string>& subs) {
    if(i >= n) {
      return 0;
    }
    
    int mx=-1;
    for(int j=1; j<n-i+1; j++) {
      string ss = s.substr(i, j);
      if(subs.find(ss) == subs.end()) {
        subs.insert(ss);
        mx=max(maxUniqueSplitHelper(s, i+j, n, subs), mx);
        subs.erase(ss);
      }
    }
    
    return mx == -1 ? -1 : mx+1;
  }
  
  int maxUniqueSplit(string s) {
    unordered_set<string> subs;
    return maxUniqueSplitHelper(s, 0, s.length(), subs);
  }
};