import java.util.*;

public class Kickstart {

  public static void solve(long t, Scanner sc) {
    int n = sc.nextInt();

    System.out.println("Case #" + t + ": " + n);
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
