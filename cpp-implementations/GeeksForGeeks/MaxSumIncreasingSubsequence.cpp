#include <iostream>
using namespace std;

int maxSumIS(int arr[], int n) {
  int results[n];
  int maxS = 0;
  for(int i=n-1; i>=0; i--) {
    if(i == n-1) {
      results[i] = arr[i];
    } else {
      maxS = arr[i];
      for(int j=i+1; j<n; j++) {
        if(arr[i] < arr[j] && results[j] + arr[i] > maxS) {
          maxS = arr[i] + results[j];
        }
      }

      results[i] = maxS;
    }
  }

  maxS = 0;
  for(int i=0; i<n; i++) {
    if(maxS < results[i]) {
      maxS = results[i];
    }
  }

  return maxS;
}  

int main() {

  int n;
  cin >> n;
  int a[n];
  for(int i =0; i< n; i++) {
    cin >> a[i];
  }

  cout << maxSumIS(a, n) << endl;
  return 1;
}
