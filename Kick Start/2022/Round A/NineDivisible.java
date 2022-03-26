import java.util.*;

class Solution {
  public static void solve(long t, Scanner sc) {
    String input = sc.nextLine();
    int n = input.length(), sum=0;
    for(int i=0; i<n; i++) {
      sum += input.charAt(i) - '0';
    }

    int num = 9 - sum % 9;
    if(num == 9) num = 0;
    StringBuilder sb = new StringBuilder(input);
    int i=0;
    while(i < n) {
      if(input.charAt(i) <= num+'0' || (i == 0 && num == 0)) {
        i++;
      } else {
        sb.insert(i, (char)(num+'0'));
        break;
      }
    }

    if(sb.length() == n) {
      sb.append((char)(num+'0'));
    }

    String result = sb.toString();
    
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


public class NineDivisible {
  
}

