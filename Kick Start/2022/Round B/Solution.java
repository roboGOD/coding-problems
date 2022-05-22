import java.util.*;

public class Solution {
  private static int[] a;
  private static int n, d;

  private static int diff(int a, int b) {
    if(a > b) {
      a = a ^ b;
      b = a ^ b;
      a = a ^ b;
    }
    int diff = Math.min(Math.abs(a-b), Math.abs(a) + Math.abs(d-b));

    // System.out.println("D " + a + " " + b + " " + diff);
    return diff;
  }

  private static long helper(int l, int r) {
    if(l < 0 || r >= n) {
      return 0;
    }

    if(l == 0 && r == n-1) {
      return diff(0, a[l]);
    }

    int cur, tl, tr; 
    long left = Long.MAX_VALUE, right = Long.MAX_VALUE;

    if(l > 0 && (r == n-1 || diff(a[l-1], a[l]) <= diff(a[r+1], a[l]))) {
      cur = a[l];
      tl = l-1;
      while(tl >= 0 && a[tl] == a[l-1]) {
        tl--;
      }
      tl++;
      tr = r+1;
      while(tr < n && a[tr] == a[tl]) {
        tr++;
      }
      tr--;
      left = diff(cur, a[tl]) + helper(tl, tr); 
    }

    if(r < n-1 && (l == 0 || diff(a[l-1], a[l]) >= diff(a[r+1], a[l]))) {
      tr = r+1;
      while(tr < n && a[tr] == a[r+1]) {
        tr++;
      }
      tr--;
      tl = l-1;
      while(tl >= 0 && a[tl] == a[tr]) {
        tl--;
      }
      tl++;
      cur = a[l];
      a[l] = a[tr];
      right = diff(cur, a[tr]) + helper(tl, tr);
      a[l] = cur;
    }

    return Math.min(left, right);
  }

  public static void solve(long t, Scanner sc) {
    n = sc.nextInt();
    d = sc.nextInt();
    a = new int[n];

    for(int i=0; i<n; i++) {
      a[i] = sc.nextInt();
    }

    long ans = Integer.MAX_VALUE;
    int j = 0, l, r;

    while(j < n) {
      l = j;
      r = j+1;
      while(r < n && a[l] == a[r]) {
        r++;
      }
      r--;
      j = r+1;
      ans = Math.min(ans, helper(l, r));
    }

    System.out.println("Case #" + t + ": " + ans);
  }

  public static void main(String[] args) {
    long t;

    Scanner sc = new Scanner(System.in);

    t = sc.nextLong();

    for(long i=0; i<t; i++) {
      solve(i+1, sc);
    }
  }
}
