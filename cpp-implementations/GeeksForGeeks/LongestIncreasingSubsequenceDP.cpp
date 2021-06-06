#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int a[], int l, int r, int val) {
  int m = r;
  int pL = -1, pR = -1;
  while (l < r && !(pL == l && pR == r) && a[m] != val) {
    pL = l;
    pR = r;
    m = l + (r - l + 1) / 2;
    if(a[m] >= val) {
      r = m;
    } else {
      l = m;
    }
  }

  return a[m] == val ? m : (a[l] > val ? -1 : l);
}

void display(int n, int a[]) {
  for(int i =0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

/**
 * 
 * Binary Search
 * 
 * O(nlogn)
 * 
 */ 
int longestSubsequenceBest(int n, int a[]) {
  if(n <= 0) {
    return 0;
  }

  int v[n+1];
  for(int i = 0; i<=n; i++) {
    v[i] = 0;
  }
  v[0] = a[0];
  int vlen = 1;
  for(int i=1; i<n; i++) {
    if(a[i] < v[0]) {
      v[0] = a[i];
    } else if(a[i] > v[vlen-1]) {
      v[vlen] = a[i];
      vlen++;
    } else {
      v[binarySearch(v, 0, vlen-1, a[i]) + 1] = a[i];
    }
  }

  return vlen;
}

/**
 * 
 * Dynamic Programming
 * 
 * O(n^2)
 * 
 */ 
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

  cout << longestSubsequenceBest(n, a) << endl;
  return 1;
}
