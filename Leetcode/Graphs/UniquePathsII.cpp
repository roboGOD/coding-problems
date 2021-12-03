#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> graph;
  vector<int> dp;
  int result, m, n;

  void addNode(vector<vector<int>>& grid, int i, int j) {
    if(grid[i][j] != 1) {
      if(j+1 < n && grid[i][j+1] != 1) {
        graph[n*i + j].push_back(n*i+j+1);
      }

      if(i+1 < m && grid[i+1][j] != 1) {
        graph[n*i + j].push_back(n*(i+1) +j);
      }
    }
  }

  int dfs(int cur) {
    if(cur == m*n-1) {
      result++;
      return 1;
    }

    if(dp[cur] != -1) {
      result+=dp[cur];
      return dp[cur];
    }

    int counts = 0;
    for(int i: graph[cur]) {
      counts += dfs(i);
    }

    dp[cur] = counts;
    return counts;
  }

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    m = obstacleGrid.size();
    n = obstacleGrid[0].size();
    graph = vector(m*n, vector(0, 0));
    dp = vector(m*n, -1);
    result = 0;
    if(obstacleGrid[m-1][n-1] == 1) {
      return 0;
    }
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) {
        addNode(obstacleGrid, i, j);
      }
    }
    dfs(0);
    return result;
  }
};