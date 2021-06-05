#include <iostream>
#include <vector>
using namespace std;


/**
 * 
 * Dynamic Programming
 * 
 **/
int longestSubsequenceDP(int n, int a[]) {
  int results[n];
  int maxI = 0;
  for(int i=n-1;i >= 0;i--) {
    if(i == n-1) {
      results[i] = 1;
    } else {
      maxI = 1;
      for(int j=i+1; j < n; j++) {
        if(a[i] < a[j] && maxI <= results[j]) {
          maxI = 1 + results[j];
        }
      }
      results[i] = maxI;
    }
  }

  maxI=0;
  for(int i=0; i<n; i++) {
    if(results[i] > maxI) {
      maxI = results[i];
    }
  }

  return maxI;
}

/**
 * Recursive Solution:
 * 
 * longestSubHelper(0, n, -1, 0, a)
 * 
 */
int longestSubHelper(int i, int n, int minVal, int maxLength, int arr[])
{
  if(i >= n) {
    return maxLength;
  }

  if(minVal != -1 && arr[i] <= arr[minVal]) {
    return longestSubHelper(i + 1, n, minVal, maxLength, arr);
  }

  int result = max(longestSubHelper(i + 1, n, i, maxLength+1, arr), longestSubHelper(i + 1, n, minVal, maxLength, arr));
  return result;
}

int longestSubsequence(int n, int a[]) {
  return longestSubHelper(0, n, -1, 0, a);
}

int main() {

  int n;
  cin >> n;
  int a[n];
  for(int i =0; i< n; i++) {
    cin >> a[i];
  }

  cout << longestSubsequenceDP(n, a) << endl;
  return 1;
}
