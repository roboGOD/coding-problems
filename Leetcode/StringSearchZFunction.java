public class StringSearchZFunction {
  
}

class Solution {
  public int strStr(String haystack, String needle) {
      int n = haystack.length() + needle.length() + 1;
      int nn = needle.length();
      
      String s = needle + "$" + haystack;
      char[] sc = s.toCharArray();
      int[] zarr = new int[n];
      
      if(nn == 0) {
          return 0;
      }
      
      int result = -1, l=0, r=0;
      boolean resultFound = false;
      int count = 0;
      int i,j;
      
      for(int k=1; k<n; k++) {
          // System.out.println("K IS " + k);
          if(k <= r && r-k > zarr[k-l]) {
              zarr[k] = zarr[k-l];
          } else {
              count = 0;
              i = 0;
              j = k;
              while(j < n && sc[i] == sc[j]) {
                  l=k;
                  r=j;
                  
                  count++;
                  // System.out.println("Comparing " + sc[i] + " " + sc[j] + " " + count);
                  
                  i++;
                  j++;
              }
              zarr[k] = count;
              if(count == nn) {
                  break;
              }
          }
      }
      
      for(int k=nn+1; k<n; k++) {
          if(zarr[k] == nn) {
              result = k-nn-1;
              break;
          }
      }
      
      return result;
  }
}
