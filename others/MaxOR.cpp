#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#define pb push_back
#define lli long long int
using namespace std;

set<lli> mp[64];

string getBits(lli num1)
{
  lli num = num1;
  std::string bin{};

  while (num > 0)
  {
    if (num % 2 == 0)
      bin.insert(bin.begin(), '0');
    else
      bin.insert(bin.begin(), '1');

    num >>= 1;
  }

  return bin;
}

int main()
{
  lli n;
  cin >> n;
  vector<lli> arr;
  for (lli i = 0; i < n; i++)
  {
    lli temp;
    cin >> temp;
    arr.pb(temp);
  }

  lli mSize = n;
  lli mOR = 0;

  for (lli index=0; index < n; index++)
  {
    lli num = arr[index];
    mOR = mOR | num;

    string bits = getBits(num);
    for(int i=0; i<bits.length(); i++) {
      if(bits[i] == '1') {
        mp[i].insert(index);
      }
    }
  }

  return 1;
}
