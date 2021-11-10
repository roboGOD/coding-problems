#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<long long int>> pmin;
    vector<vector<long long int>> pmax;
    long long int helper(vector<vector<int>>& grid,  int i, int j) {
      int rows = grid.size();
      int cols = rows > 0 ? grid[0].size() : 0; 
      
      if(i >= rows || j >= cols) {
        return -1;
      }
      
      if(i == rows-1 && j==cols-1) {
        visited[i][j] = true;
        pmin[i][j] = grid[i][j];
        pmax[i][j] = grid[i][j];
        return grid[i][j];
      }
      
      if(visited[i][j]) {
        return max(pmin[i][j], pmax[i][j]);
      }
      
      long long int right=-1;
      if(j+1 < cols) {
         if(visited[i][j+1]) {
           right=grid[i][j]*pmin[i][j+1];
         } else {
           right=grid[i][j]*helper(grid, i, j+1);
         }
      }
      long long int down=-1;
      if(i+1 < rows) {
        if(visited[i+1][j]) {
          down=grid[i][j]*pmin[i+1][j];
        } else {
          down=grid[i][j]*helper(grid, i+1, j);
        }
      }
      
      if(j+1 < cols && i+1 < rows) {
        pmin[i][j] = max(right, down);
      } else if(i+1 < rows) {
        pmin[i][j] = down;
      } else if(j+1 < cols) {
        pmin[i][j] = right;
      } else {
        pmin[i][j] = -1;
      }
      
      cout << "IJ " << i << " " << j << endl;
      cout << "PR " << right << " " << down << " " << pmin[i][j] << endl;
      
      visited[i][j] = true;
      return pmin[i][j];
    }
  
    int maxProductPath(vector<vector<int>>& grid) {
      int rows = grid.size();
      int cols = rows > 0 ? grid[0].size() : 0;
      for(int i=0; i<rows; i++) {
        vector<bool> vv;
        vector<long long int> pp;
        for(int j=0; j<cols; j++) {
          vv.push_back(false);
          pp.push_back(1);
        }
        visited.push_back(vv);
        pmin.push_back(pp);
      }
      long long int pmin=helper(grid, 0, 0);
      
      if(pmin < 0) {
        return -1;
      }
      
      return pmin%1000000007;
    }
};

int main() {
  cout << "HELLO" << endl;
  return 0;
}
