#include<bits/stdc++.h>
using namespace std;

vector<string> split(string s, string del = "/") {
  int start = 0;
  int end = s.find(del);
  vector<string> result;
  while (end != -1) {
    result.push_back(s.substr(start, end - start));
    start = end + del.size();
    end = s.find(del, start);
  }
  result.push_back(s.substr(start, end - start));
  return result;
}

vector<int> decToBin(int num) {
  vector<int> result;
  while(num > 0) {
    result.push_back(num%2);
    num = num/2;
  }

  if(result.size() == 0) {
    result.push_back(0);
  }

  reverse(result.begin(), result.end());
  return result;
}


int binToDec(vector<int>& num) {
  int result=0;
  int n=num.size();
  for(int i=0; i<n; i++) {
    result += num[i]*pow(2, n-i-1);
  }

  return result;
}

vector<int> binComplement(vector<int>& bin) {
  vector<int> result;
  for(int i=0; i<bin.size(); i++) {
    result.push_back(1-bin[i]);
  }

  return result;
}
