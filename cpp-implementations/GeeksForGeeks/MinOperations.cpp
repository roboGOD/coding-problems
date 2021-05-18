#include <iostream>
#include <map>
#define pb push_back
#define lli long long int
using namespace std;

map<lli, lli> minOps;

lli minOperations(lli state, lli target) {
  if(minOps.find(state) != minOps.end()) {
    return minOps.find(state)->second;
  }

  if(state == target) {
    return 0;
  } else if(target == state/2 || target == state + 1) {
    return 1;
  } else if(state == 0) {
    return 1 + minOperations(state+1, target);
  } else if(state > target) {
    return -1;
  }
  lli addR = minOperations(state+1, target);
  lli mulR = minOperations(state*2, target);
  lli result;
  if(addR < 0 && mulR < 0) {
    result = -1;
  } else if(addR < 0) {
    result = 1 + mulR;
  } else if(mulR < 0) {
    result = 1 + addR;
  } else {
    result = min(1 + addR, 1 + mulR);
  }
  minOps.insert(pair<lli, lli>(state, result));
  return result;
}

lli minOperationsV2(lli n) {
  minOps.insert(pair<lli, lli>(n, 0));
  lli total = 0;

  for(lli i=n-1; i >=0; i--) {
    lli plus = 0;
    lli mul = 0;
    if(minOps.find(i+1) != minOps.end()) {
      plus = minOps.find(i+1)->second;
    }
    if(minOps.find(i*2) != minOps.end()) {
      mul = minOps.find(i*2)->second;
    }
    if(i * 2 > n || i == 0) {
      total = plus + 1;
    } else {
      total = min(plus, mul) + 1;
    }

    minOps.insert(pair<lli, lli>(i, total));
  }

  // lli index = 0;
  // for(auto i : minOps) {
  //   cout << index << " " << i.second  << endl;
  //   index++;
  // }

  return minOps.find(0)->second;
}

/**
 *  Locate Nearest power of 2. 
 **/
int minOperationsV3(int n) {
  if(n == 0) {
    return 0;
  } else if(n == 1) {
    return 1;
  } else if(n % 2 == 0) {
    return n/2;
  } else {
    return 2 + n/2;
  }
}

int main() {
  lli n;
  cin >> n;
  cout << minOperationsV3(n) << endl; 
  return 1;
}
