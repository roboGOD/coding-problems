import java.util.*;

public class InfiniteArea {
  
}

class Solution {
  static double PIE = 3.1415926535;

  private static double area(double r) {
    return PIE*r*r;
  }

  public static void solve(long t, Scanner sc) {
    int r = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();

    double ans = 0d;

    while(r > 0) {
      ans += area(r);
      r = r*a;
      ans += area(r);
      r = r/b;
    }

    System.out.println("Case #" + t + ": " + String.format("%.6f", ans));
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
