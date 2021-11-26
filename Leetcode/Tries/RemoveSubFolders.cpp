#include<bits/stdc++.h>
using namespace std;


struct Node {
  char c;
  bool isPath;
  vector<Node *> children;

  Node(): isPath(false), c('/'), children(27, nullptr) {}
};

class Solution {
public:
  Node* root;
  vector<string> results;

  int getCharIndex(char& c) {
    if(c == '/') {
      return 26;
    } else {
      return c - 'a';
    }
  }

  void addFolder(string& folder, Node* cur) {
    for(char& c: folder) {
      if(cur == root && c == '/') {
        continue;
      }
      Node* next=cur->children[getCharIndex(c)];
      if(next == nullptr) {
        next = new Node();
        next->c = c;
        cur->children[getCharIndex(c)] = next;
      }
      cur = next;
    }
    cur->isPath = true;
  }

  void getPaths(Node* cur, vector<char>& pathV) {
    if(cur == nullptr) {
      return;
    }
    pathV.push_back(cur->c);
    bool isPath = false;
    if(cur->isPath) {
      results.push_back(string(pathV.begin(), pathV.end()));
      isPath = true;
    }
    for(int i=0; i<27; i++) {
      if(!isPath || i!=26) {
        getPaths(cur->children[i], pathV);
      }
    }
    pathV.pop_back();
  }
  
  vector<string> removeSubfolders(vector<string>& folder) {
    root= new Node();
    for(string& s: folder) {
      addFolder(s, root);
    }
    results = {};
    vector<char> pathV;
    getPaths(root, pathV);
    return results;
  }
};