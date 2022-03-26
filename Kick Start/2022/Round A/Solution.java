import java.util.*;

public class Solution {
  public static long digitP(long n) {
    long res = 1;
    while(n > 0) {
      res *= n%10;
      n = n/10;
    }

    return res;
  }

  public static long digitS(long n) {
    long res = 0;
    while(n > 0) {
      res += n%10;
      n = n/10;
    }

    return res;
  }

  public static boolean isInteresting(long n) {
    boolean ist = false;
    ist = digitP(n)%digitS(n) == 0;
    return ist;
  }

  public static void solve(long t, Scanner sc) {
    long a = Long.parseLong(sc.next());
    long b = Long.parseLong(sc.next());
    sc.nextLine();
    long result = 0;

    for(long i=a; i<=b; i++) {
      if(isInteresting(i)) {
        result++;
      }
    }
    
    System.out.println("Case #" + t + ": " + result);
  }

  public static void main(String[] args) {
    long t;

    Scanner sc = new Scanner(System.in);

    t = Long.parseLong(sc.nextLine());

    for(long i=0; i<t; i++) {
      solve(i+1, sc);
    }
  }
}
