#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  
  void combinations(int n, int k, int x, vector<int>& cur, vector<bool>& visited, vector<vector<int>>& result) {
    if(cur.size() == k) {
      result.push_back(cur);
      return;
    }
    for(int i=x; i<=n; i++) {
      if(visited[i-1]) {
        continue;
      }

      cur.push_back(i);
      visited[i-1] = true;
      combinations(n, k, i+1, cur, visited, result);
      visited[i-1] = false;
      cur.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<bool> visited(n, false);
    vector<int> cur;
    combinations(n, k, 1, cur, visited, result);
    return result;
  }
};