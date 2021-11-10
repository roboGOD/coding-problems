#include<bits/stdc++.h>
using namespace std;

long long int MAX=pow(2, 10);
class MyCalendar {
public:
  vector<int> stree;
  MyCalendar():stree(MAX, 0) {}

  bool isBooked(int i, int ns, int ne, int &start, int &end) {
    if(ne <= ns) {
      return false;
    }

    if(ns >= end || ne <= start) {
      return false;
    }

    if(ns >= start && ne < end && stree[i] > 0) {
      return true;
    }

    int mid=(ns+ne)/2;
    bool left=isBooked(2*i+1, ns, mid, start, end);
    bool right=isBooked(2*i+2, mid, ne, start, end);

    return left && right;
  }

  int book(int i, int ns, int ne, int &start, int &end) {
    cout << "> " << i << " " << ns << " " << ne << endl;
    if(ne <= ns) {
      return 0;
    }

    if(ns >= end || ne <= start) {
      return 0;
    }
    
    if(ne-ns == 1) {
      stree[i]=1;
      return 1;
    }

    if(ns >= start && ne <= end) {
      stree[i]=ne-ns;
      return stree[i];
    }
    
    int mid=(ns+ne)/2;
    int left=book(2*i+1, ns, mid, start, end);
    int right=book(2*i+2, mid, ne, start, end);

    stree[i]=left+right;
    return stree[i];
  }
  
  bool book(int start, int end) {
    bool isb = isBooked(0, 0, MAX, start, end);
    cout << start << " " << end << endl;
    for(auto x: stree) {
      cout << x << " ";
    }
    cout << endl;
    
    if(isb) {
      return false;
    } else {
      cout << "BOOKING" << endl;
      int booked = book(0, 0, MAX, start, end);
      return true;
    }
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
