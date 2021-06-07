#include <iostream>
using namespace std;

/**
 * Recursive Solution with memoization
 */
int knapsackHelper(int X, int i, int wt[], int val[], int n, int* memo[]) {
  if(X <= 0 || i >= n || i < 0) {
    return 0;
  }

  if(memo[i][X] != -1) {
    return memo[i][X];
  }

  if(i == n-1) {
    if(wt[i] <= X) {
      memo[i][X] = val[i];
      return val[i];
    } else {
      memo[i][X] = 0;
      return 0;
    }
  }
  
  if(X < wt[i]) {
    int result = knapsackHelper(X, i+1, wt, val, n, memo);
    memo[i][X] = result;
    return result;
  }

  int result1 = val[i] + knapsackHelper(X - wt[i], i + 1, wt, val, n, memo);
  int result2 = knapsackHelper(X, i + 1, wt, val, n, memo);
  int result = max(result1, result2);
  memo[i][X] = result;
  return result;
}

/**
 * Test Case:
 * 58
 * 41
 * 57 95 13 29 1 99 34 77 61 23 24 70 73 88 33 61 43 5 41 63 8 67 20 72 98 59 46 58 64 94 97 70 46 81 42 7 1 52 20 54 81 3 73 78 81 11 41 45 18 94 24 82 9 19 59 48 2 72
 * 83 84 85 76 13 87 2 23 33 82 79 100 88 85 91 78 83 44 4 50 11 68 90 88 73 83 46 16 7 35 76 31 40 49 65 2 18 47 55 38 75 58 86 77 96 94 82 92 10 86 54 49 65 44 77 22 81 52
 *
 * Its Correct output is:
 * 223
*/
int knapSack(int W, int wt[], int val[], int n) {
  int* memo[n];
  for(int i=0; i<n; i++) {
    memo[i] = new int[W+1];
    for(int j=1; j<=W; j++) {
      memo[i][j] = -1;
    }
  }
  return knapsackHelper(W, 0, wt, val, n, memo);
}

int main() {

  int n, W;
  cin >> n >> W;
  int wt[n], val[n];
  for(int i =0; i< n; i++) {
    cin >> val[i];
  }
  for(int i =0; i< n; i++) {
    cin >> wt[i];
  }

  cout << knapSack(W, wt, val, n) << endl;
  return 1;
}
