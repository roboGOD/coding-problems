import java.util.*;

public class PalindromeFactors {
  
}

class Solution {

  private static boolean isPalindrome(long n) {
    long temp = n;
    long y = 0;
    while(temp > 0) {
      y = y*10 + temp%10;
      temp = temp/10;
    }

    return y == n;
  }

  public static void solve(long t, Scanner sc) {
    long n = sc.nextLong();
    long ans = 0;

    for(long i=1; i<=Math.sqrt(n); i++) {
      if(n % i == 0) {
        if(isPalindrome(i)) {
          ans++;
        }

        if(n/i != i) {
          if(isPalindrome(n/i)) {
            ans++;
          }
        }
      }
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

