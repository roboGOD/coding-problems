/*
 * Solve with O(n) instead of O(nlog(n))!
 */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

typedef priority_queue <ll, vector<ll>, greater<ll>> pq;
class Solution {
public:
  
  void operate(pq& mq, ll mn, unordered_set<ll>& s) {
    mq.pop();
    if(s.find(mn*2) == s.end()) {
      mq.push(mn*2);
      s.insert(mn*2);
    }
    if(s.find(mn*3) == s.end()) {
      mq.push(mn*3);
      s.insert(mn*3);
    }
    if(s.find(mn*5) == s.end()) {
      mq.push(mn*5);
      s.insert(mn*5);
    }
  }

  ll nthUglyNumber(ll n) {
    if(n <= 6) {
      return n;
    }
    
    ll mn = 1, tp;
    pq l1q;
    pq l2q;
    pq l3q;
    pq mq;
    ll l1, l2, l3;
    ll count=1;
    
    unordered_set<ll> s;
    
    l1q.push(2);
    l2q.push(3);
    l3q.push(5);
    
    s.insert(2);
    s.insert(3);
    s.insert(5);
    while(count < n) {
      l1=l1q.top();
      l2=l2q.top();
      l3=l3q.top();
      cout << mn << endl;
      cout << l1 << " " << l2 << " " << l3 << endl;
      if(l1 <= l2 && l1 <= l3) {
        mn = l1;
        operate(l1q, mn, s);
      } else if(l2 <= l1 && l2 <= l3) {
        mn = l2;
        operate(l2q, mn, s);
      } else if(l3 <= l1 && l3 <= l2) {
        mn = l3;
        operate(l3q, mn, s);
      }
      
      count++;
    }
    
    return mn;
  }
};