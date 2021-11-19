#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

class Solution {
public:
  vector<int> dp;
  int findSum(vector<int>& arr, int& k, int l) {
    int n=arr.size();
    if(l >= n) {
      return 0;
    }
    if(dp[l] != -1) {
      return dp[l];
    }

    int mx=-1;
    int mEl=0;
    for(int i=l; i<l+k && i<n; i++) {
      if(i == l || mEl < arr[i]) {
        mEl=arr[i];
      }
      mx = max(mEl*(i-l+1)+findSum(arr, k, i+1), mx);
    }

    dp[l]=mx;
    return mx;
  }

  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    dp=vector(arr.size(), -1);
    return findSum(arr, k, 0);
  }
};