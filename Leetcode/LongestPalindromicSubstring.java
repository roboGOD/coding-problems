public class LongestPalindromicSubstring {
  
}

class Solution {
  
  //////////////////////////////////////////////////////
  // DP Solution
  public String longestPalindrome(String s) {
      int maxLen = 0;
      String result = "";
      int ri=-1, rj=-1;
      int n = s.length();
      boolean[][] dp = new boolean[n][n];
      
      for(int k=0; k<n; k++) {
          for(int i=0; k+i<n; i++) {
              int j = i+k;
              if(j-i == 0) {
                  dp[i][j] = true;
              } else if(j-i == 1) {
                  dp[i][j] = s.charAt(i) == s.charAt(j);
              } else {
                  dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i+1][j-1];
              }
              
              // System.out.println(i + " " + j + " " + dp[i][j]);
              
              if(dp[i][j] && j-i+1 >= maxLen) {
                  maxLen = j-i+1;
                  ri = i;
                  rj = j;
              }
          }
      }
      
      if(ri != -1 && rj != -1) {
          result = s.substring(ri, rj+1);
      }
      
      return result;
  }
}
