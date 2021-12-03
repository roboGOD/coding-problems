#include<bits/stdc++.h>
using namespace std;
#define ll long int
#define ld double

typedef pair<ld, array<int, 2>> mpair;
typedef priority_queue <mpair> priority_q;

class Solution {
public:
  ld avgDiff(array<int, 2> arr) {
    return ((ld)arr[0] + 1) / ((ld)arr[1] + 1) - (ld)arr[0]/(ld)arr[1];
  }

  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    ld total=0;
    priority_q pq;
    for(vector<int>& c: classes) {
      ld diff = avgDiff({c[0], c[1]});
      total += (ld)c[0]/(ld)c[1];
      pq.push({diff, {c[0], c[1]}});
    }

    for(int i=0; i<extraStudents; i++) {
      auto [diff, c] = pq.top();
      pq.pop();
      total += diff;
      c[0]++;
      c[1]++;
      pq.push({avgDiff(c), c});
    }

    return total/classes.size();
  }
};