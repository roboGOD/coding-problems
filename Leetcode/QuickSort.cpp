#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

class Solution {
public:
  void swap(vector<int>& nums, int i, int j) {
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
  }

  int quickSortHelper(vector<int>& nums, int l, int r) {
    int pEl=nums[r];
    int pivot=r;
    int i=l;
    while(i<pivot) {
      if(nums[i] <= pEl) {
        i++;
      } else {
        swap(nums, i, pivot);
        pivot--;
        swap(nums, i, pivot);
      }
    }
    return pivot;
  }
  
  void quickSort(vector<int>& nums, int l, int r) {
    if(l >= r) {
      return;
    }
    
    int pI=quickSortHelper(nums, l, r);
    quickSort(nums, l, pI-1);
    quickSort(nums, pI+1, r);
  }
  
  void sortColors(vector<int>& nums) {
    quickSort(nums, 0, nums.size()-1);
  }
};