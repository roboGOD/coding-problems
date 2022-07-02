public class Utils {
  private long modMul(long a, long b, long mod) {
    long res = 0;
    a %= mod;
    
    while(b > 0) {
        if(b%2 == 1) {
            res = (res + a)%mod;
        }
        
        a = (2*a)%mod;
        b >>= 1;
    }
    
    return res;
  }
}
