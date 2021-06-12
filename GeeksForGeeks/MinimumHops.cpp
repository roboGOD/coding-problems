#include <iostream>
using namespace std;

/**
 * 
 * Using BFS and ignoring visited nodes
 * 
 */
int minJumps(int arr[], int n){
  int level=0, l=0, r=0, visited=0;
  while(r < n-1 && r != -1 && l < n - 1) {
    level++;
    visited = r;

    for(int i=l; i< visited+1; i++) {
      r = max(r, arr[i] + i);
    }

    if(r == visited) {
      r = -1;
      level = -1;
    } else {
      l = visited + 1;
    }
  }

  return r >= n-1 ? level : -1;
}

int main() {

  int n;
  cin >> n;
  int a[n];
  for(int i =0; i< n; i++) {
    cin >> a[i];
  }

  cout << minJumps(a, n) << endl;
  return 1;
}
