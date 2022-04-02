import java.util.ArrayDeque;

public class DontGetVolunteered {
  public static void main(String args[]) {
    System.out.println(Solution.solution(0, 1));
    System.out.println(Solution.solution(19, 36));
  }
}

class Solution {
  private static int[] visited = new int[64];
  private static int[] variations = new int[8];

  private static boolean isValid(int i) {
    return i >= 0 && i < 64;
  }

  private static boolean isValid(int i, int j) {
    return i >= 0 && i < 8 && j >=0 && j < 8;
  }

  private static int getPosition(int i, int j) {
    int val = i*8+j;
    return isValid(i, j) ? val : Integer.MAX_VALUE;
  }

  private static void getVariations(int p) {
    int i=p/8, j=p%8;
    variations[0] = getPosition(i+1, j+2);
    variations[1] = getPosition(i+1, j-2);
    variations[2] = getPosition(i-1, j+2);
    variations[3] = getPosition(i-1, j-2);
    variations[4] = getPosition(i+2, j+1);
    variations[5] = getPosition(i+2, j-1);
    variations[6] = getPosition(i-2, j+1);
    variations[7] = getPosition(i-2, j-1);
  }

  public static int solution(int src, int dest) {
    ArrayDeque<Integer> q = new ArrayDeque<>();
    ArrayDeque<Integer> levels = new ArrayDeque<>();

    for(int i=0; i<64; i++) {
      visited[i] = Integer.MAX_VALUE;
    }

    visited[src] = 0;
    q.add(src);
    levels.add(0);
    int lvl, node, ans=Integer.MAX_VALUE;

    while(!q.isEmpty()) {
      node = q.poll();
      lvl = levels.poll();

      // System.out.println("--------------------------------");
      // System.out.println("Node " + node + " " + lvl);
      if(node == dest) {
        ans = Math.min(ans, lvl);
      } else if(lvl <= visited[node]) {
        getVariations(node);
        for(int vars: variations) {
          if(isValid(vars) && lvl + 1 < visited[vars]) {
            // System.out.println("Vars " + vars);
            visited[vars] = lvl + 1;
            q.add(vars);
            levels.add(lvl+1);
          }
        }
      }
    }

    return ans;
  }
}
