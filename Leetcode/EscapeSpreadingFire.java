class Solution {
  int m, n;
  int[][] grid, copy;
  boolean[][] visited;
  boolean fireSpread;
  
  
  private boolean helper(int wt) {
      for(int i=0; i<wt; i++) {            
          if(!spread()) {
              break;
          }
      }
      
      return dfs(0, 0);
  }
  
  private boolean call(int i, int j) {
      if(isValidFree(i, j) && !visited[i][j]) {
          return dfs(i, j);
      }
      
      return false;
  }
  
  private boolean dfs(int i, int j) {
      if(i == m-1 && j == n-1) {
          return true;
      }
      
      if(visited[i][j]) {
          return false;
      }
      
      fireSpread = spread();
      visited[i][j] = true;
      boolean found = false;
      found = call(i+1, j);
      if(!found) found = call(i-1, j);
      if(!found) found = call(i, j-1);
      if(!found) found = call(i, j+1);
      
      return found;
  }
  
  private boolean isValid(int i, int j) {
      return i >= 0 && i < m && j >= 0 && j < n;
  }
  
  private boolean isFree(int i, int j) {
      return copy[i][j] == 0;
  }
  
  private boolean isValidFree(int i, int j) {
      return isValid(i, j) && isFree(i, j);
  }
  
  private boolean spread() {
      int cnt = 0;
      for(int i=0; i<m; i++) {
          for(int j=0; j<n; j++) {
              if(copy[i][j] == 1) {
                  if(isValidFree(i-1, j)) {
                      copy[i-1][j] == 3;
                      cnt++;
                  }
                  
                  if(isValidFree(i+1, j)) {
                      copy[i+1][j] == 3;
                      cnt++;
                  }
                  
                  if(isValidFree(i, j-1)) {
                      copy[i][j-1] == 3;
                      cnt++;
                  }
                  
                  if(isValidFree(i, j+1)) {
                      copy[i][j+1] == 3;
                      cnt++;
                  }
              }
          }
      }
      
      if(cnt != 0) {
          for(int i=0; i<m; i++) {
              for(int j=0; j<n; j++) {
                  if(copy[i][j] == 3) {
                      copy[i][j] == 1;
                  }
              }
          }
      }
      
      return cnt != 0;
  }
  
  private void initCopy() {
      for(int i=0; i<m; i++) {
          for(int j=0; j<n; j++) {
              copy[i][j] = grid[i][j];
          }
      }
  }
  
  private void initVis() {
      for(int i=0; i<m; i++) {
          for(int j=0; j<n; j++) {
              visited[i][j] = false;
          }
      }
  }
  
  public int maximumMinutes(int[][] g) {
      grid = g;
      m = grid.length;
      n = grid[0].length;
      copy = new int[m][n];
      visited = new boolean[m][n];
      
      int res = 0;
      fireSpread = true;
      
      while(true) {
          initCopy();
          initVis();
          boolean found = helper(res);
          if(found && !fireSpread) {
              return 1000_000_000;
          } else if(!found && res == 0) {
              return -1;
          } else if(!found) {
              break;
          }
          res++;
      }
      
      return res;
      
  }
}