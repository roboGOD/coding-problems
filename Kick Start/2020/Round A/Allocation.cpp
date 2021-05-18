
#include "iostream"
#include "vector"
#include "algorithm"
#define lli long long int
using namespace std;

int main() {

  lli t;
  cin >> t;
  lli ct = 0;
  while(ct < t) {
    lli n, b;
    cin >> n;
    cin >> b;
    vector<lli> v;

    for(lli i=0; i<n; i++) {
      lli inputNum;
      cin >> inputNum;
      v.push_back(inputNum);
    }

    sort(v.begin(), v.end());
    lli currentSum = 0;
    lli i = 0;
    while(i < n && currentSum <= b) {
      currentSum += v[i];
      i++;
    }

    cout << "Case #" << ct + 1 << ": " << (currentSum == b ? i : i-1) << endl;

    ct++;
  }

  return 0;
}
