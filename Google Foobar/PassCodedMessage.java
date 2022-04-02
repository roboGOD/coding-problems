public class PassCodedMessage {
  public static void main(String args[]) {
    System.out.println(Solution.solution(new int[]{3, 1, 4, 1}));
    System.out.println(Solution.solution(new int[]{3, 1, 4, 1, 5, 9}));
  }
}

class Solution {
  private static boolean[] visited = new boolean[10];
  private static int ans = 0;

  private static void solutionHelper(int[] l, int num) {
    if(num % 3 == 0) {
      ans = Math.max(num, ans);
    }

    for(int i=0; i<l.length; i++) {
      if(!visited[i]) {
        visited[i] = true;
        solutionHelper(l, num*10 + l[i]);
        visited[i] = false;
      }
    }
  }

  public static int solution(int[] l) {
    int n = l.length;
    for(int i=0; i<n; i++) {
      visited[i] = false;
    }
    ans = 0;
    solutionHelper(l, 0);
    return ans;
  }
}
