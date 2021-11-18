#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class NumArray {
public:
  vector<ll> stree;
  ll sz;
  ll n;
  vector<int> arr;

  NumArray(vector<int>& nums) {
    createTree(nums);
  }

  void createTree(vector<int>& nums) {
    arr=nums;
    n=nums.size();
    sz=1;
    while(sz < n) {
      sz*=2;
    }

    sz*=2;
    sz-=1;

    stree=vector<ll>(sz, 0);
    createTree(nums, 0, n-1, 0);
  }

  int createTree(vector<int>& nums, ll ns, ll ne, ll i) {
    if(ns == ne) {
      stree[i] = nums[ns];
      return stree[i];
    }

    ll mid = (ns+ne)/2;
    stree[i] = createTree(nums, ns, mid, 2*i+1) + createTree(nums, mid+1, ne, 2*i+2);
    return stree[i];
  }

  void update(ll diff, ll i, ll l, ll r, ll ti) {
    if(i < l || i > r) {
      return;
    }

    stree[ti] += diff;
    if(l == r && l == i) {
      return;
    }

    ll mid=(l+r)/2;
    // cout << "DIV TO " << l << " " << mid << " " << r << endl;
    update(diff, i, l, mid, 2*ti+1);
    update(diff, i, mid+1, r, 2*ti+2);
  }
  
  void update(ll index, ll val) {
    ll diff=val-arr[index];
    arr[index]+=diff;
    update(diff, index, 0, n-1, 0);
  }

  ll getSum(ll l, ll r, ll nl, ll nr, ll i) {
    if(nr < l || nl > r || l > r || i >= sz) {
      return 0;
    }

    if(nl >= l && nr <= r) {
      return stree[i];
    }

    ll mid=(nl+nr)/2;
    return getSum(l, r, nl, mid, 2*i+1) + getSum(l, r, mid+1, nr, 2*i+2);
  }
  
  ll sumRange(ll left, ll right) {
    return getSum(left, right, 0, n-1, 0);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */