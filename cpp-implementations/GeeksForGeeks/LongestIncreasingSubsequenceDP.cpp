#include <iostream>
#include <vector>
using namespace std;

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

  cout << longestSubsequence(n, a) << endl;
  return 1;
}
