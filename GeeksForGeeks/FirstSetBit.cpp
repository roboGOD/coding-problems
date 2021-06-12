#include <iostream>
using namespace std;

unsigned int getFirstSetBit(int n)
{   
  if(n == 0) {
    return 0;
  }
  
  int count = 1;
  
  while(n % 2 == 0) {
    n = n/2;
    count++;
  }
  
  return count;
}

int main() {

  int n;
  cin >> n;

  cout << getFirstSetBit(n) << endl;
  return 0;
}
