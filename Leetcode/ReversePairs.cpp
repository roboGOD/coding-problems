#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int count;
  
  void merge(vector<int>& arr, int l1, int r1, int l2, int r2) {
    int n1=r1-l1+1;
    int n2=r2-l2+1;

    cout << "L R " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;

    int a1[n1], a2[n2];
    for(int i=0; i<n1; i++) {
      a1[i]=arr[i+l1];
    }
    for(int i=0; i<n2; i++) {
      a2[i]=arr[i+l2];
    }

    int curCount=0;

    int i=0, j=0;
    while(j < n2) {
      int nj = a2[j]*2;
      while(i < n1 && a1[i] > nj) {
        curCount++;
        i++;
      }
      count += curCount;
      j++;
    }

    i=0;
    j=0;
    int k=l1;
    while(i < n1 && j < n2) {
      if(a1[i] > a2[j]) {
        arr[k]=a1[i];
        i++;
      } else {
        arr[k]=a2[j];
        j++;
      }

      k++;
    }

    while(i < n1) {
      arr[k]=a1[i];
      i++;
      k++;
    }

    while(j < n2) {
      arr[k]=a2[j];
      j++;
      k++;
    }
  }

  void mergeSort(vector<int>& arr, int l, int r) {
    if(l < r) {
      int mid = (l+r)/2;
      mergeSort(arr, l, mid);
      mergeSort(arr, mid+1, r);
      merge(arr, l, mid, mid+1, r);
    }
  }

  int reversePairs(vector<int>& nums) {
    count=0;
    mergeSort(nums, 0, nums.size()-1);
    return count;
  }
};