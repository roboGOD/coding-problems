#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void addNode(queue<vector<int>> &q, vector<vector<char>>& maze, vector<int>& n, int level, vector<vector<bool>> &visited) {
    int rows=maze.size();
    int cols=0;
    int i=n[0];
    int j=n[1];
    if(rows > 0) {
      cols=maze[0].size();
    }
    
    if(i-1 >= 0 && maze[i-1][j] != '+' && !visited[i-1][j]) {
      visited[i-1][j] = true;
      q.push({i-1, j, level});
    }
    if(i+1 < rows && maze[i+1][j] != '+' && !visited[i+1][j]) {
      visited[i+1][j] = true;
      q.push({i+1, j, level});
    }
    if(j-1 >= 0 && maze[i][j-1] != '+' && !visited[i][j-1]) {
      visited[i][j-1] = true;
      q.push({i, j-1, level});
    }
    if(j+1 < cols && maze[i][j+1] != '+' && !visited[i][j+1]) {
      visited[i][j+1] = true;
      q.push({i, j+1, level});
    }
    
  }

  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<vector<int>> q;
    int rows=maze.size();
    int cols=0;
    if(rows > 0) {
      cols=maze[0].size();
    }
    vector<vector<bool>> visited(rows, vector(cols, false));
    visited[entrance[0]][entrance[1]] = true;
    addNode(q, maze, entrance, 1, visited);

    while(q.size() > 0) {
      vector<int>& node = q.front();
      if(node[0] == 0 || node[1] == 0 || node[0] == rows-1 || node[1] == cols-1) {
        return node[2];
      }

      addNode(q, maze, node, node[2]+1, visited);
      q.pop();
    }

    return -1;
  }
};