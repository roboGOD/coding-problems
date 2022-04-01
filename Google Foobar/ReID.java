import java.util.ArrayList;

class Solution {
  private static final int MAX_SL = 10005;
  private static ArrayList<Long> primes = new ArrayList<>();
  private static StringBuilder sb = new StringBuilder();
  
  static {
      computePrimes();
  }
  
  private static void computePrimes() {
      primes.add(2l);
      sb.append(2);
      long i = 3;
      
      while(sb.length() < MAX_SL) {
          if(isPrime(i)) {
              primes.add(i);
              sb.append(i);
          }
          
          i += 2;
      }
  }

  private static boolean isPrime(long num) {
    for(long i: primes) {
      if(num % i == 0) {
        return false;
      }

      if(i*i > num) {
        return true;
      }
    }

    return true;
  }
  
  public static String solution(int i) {
      // Your code here

      return sb.substring(i, i+5);
  }
}

public class ReID {
  public static void main(String args[]) {
    System.out.println(Solution.solution(0));
    System.out.println(Solution.solution(1));
    System.out.println(Solution.solution(2));
    System.out.println(Solution.solution(3));
    System.out.println(Solution.solution(10000));
  } 
}
