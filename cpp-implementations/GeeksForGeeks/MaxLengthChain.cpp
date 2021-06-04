#include <iostream>
#include <vector>
#include <functional>
#define pb push_back
#define lli long long int
using namespace std;

/*
  The structure to use is as follows
*/
struct val {
  int first;
  int second;
};

int maxChainLen(struct val p[], int n) {
  vector<val> vec;
  vec.assign(p, p+n);
  sort(vec.begin(), vec.end(), [](const val & a, const val & b) -> bool {
    return a.second < b.second;
  });

  int count=0;
  val curEle;

  for(int i=0; i<n; i++) {
    if(i == 0 || curEle.second < vec[i].first) {
      count++;
      curEle = vec[i];
    }
  }

  return count;
}

int main() {
  int n;
  cin >> n;

  struct val p[n];
  for(int i=0; i<n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  cout << maxChainLen(p, n) << endl;
  return 1;
}