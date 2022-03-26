import java.util.*;

class Solution {
  public static void solve(long t, Scanner sc) {
    String input = sc.nextLine();
    String typed = sc.nextLine();
    String result = "";

    int n = input.length();
    int m = typed.length();    
    int i=0, j=0;

    while(i < n && j < m) {
      if(input.charAt(i) == typed.charAt(j)) {
        i++;
        j++;
      } else {
        j++;
      }
    }

    if(i < n) {
      result = "IMPOSSIBLE";
    } else {
      result = String.valueOf(m-n);
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


public class SpeedTyping {}
