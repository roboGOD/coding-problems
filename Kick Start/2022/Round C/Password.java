import java.util.*;

public class Password {
  
}

public class Solution {

  public static void solve(long t, Scanner sc) {
    int n = sc.nextInt();
    sc.nextLine();

    int up = 0, low = 0, digit = 0, sp = 0;

    String s = sc.nextLine();

    for(char c: s.toCharArray()) {
      if(Character.isDigit(c)) {
        digit++;
      } else if(Character.getType(c) == Character.UPPERCASE_LETTER) {
        up++;
      } else if(Character.getType(c) == Character.LOWERCASE_LETTER) {
        low++;
      } else if(c == '#' || c == '@' || c == '*' || c == '&') {
        sp++;
      }
    }

    StringBuilder sb = new StringBuilder(s);

    if(up == 0) {
      sb.append('A');
      n++;
    }

    if(low == 0) {
      sb.append('a');
      n++;
    }

    if(digit == 0) {
      sb.append('0');
      n++;
    }

    while(sp == 0 || n < 7) {
      sb.append('@');
      n++;
      sp++;
    }

    System.out.println("Case #" + t + ": " + sb.toString());
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
