#include<bits/stdc++.h>
using namespace std;

struct Node {
  bool isEndNode;
  Node* m[26];

  Node() {
    isEndNode=false;
    for(int i=0; i<26; i++) {
      m[i] = nullptr;
    }
  }
};

class Solution {
public:
    Node* root;

    void createTrie(vector<string> &list) {
      root = new Node();

      for(string &s: list) {
        Node* curNode = root;
        for(char &c: s) {
          
          if(curNode->m[c-97] == nullptr) {
            curNode->m[c-97] = new Node();
          }

          curNode=curNode->m[c-97];
        }

        curNode->isEndNode=true;
      }
    }

    Node* findNode(string &s) {
      Node *curNode = root;
      for(char &c: s) {
        if(curNode->m[c-97] == nullptr) {
          return nullptr;
        }

        curNode = curNode->m[c-97];
      }

      return curNode;
    }

    void findAllStrings(Node* node, string &prefix, vector<string> &list) {
      if(node == nullptr || list.size() >= 3) {
        return;
      }

      if(node->isEndNode) {
        list.push_back(prefix);
        if(list.size() >= 3) {
          return;
        }
      }

      for(int i=0; i<26; i++) {
        char c=97+i;
        if(node->m[c-97] != nullptr) {
          auto x = node->m[c-97];
          prefix += c;
          findAllStrings(x, prefix, list);
          prefix.pop_back();

          if(list.size() >= 3) {
            return;
          }
        }
      }
    }

    vector<string> searchTrie(string &s) {
      Node *curNode = findNode(s);
      vector<string> result;
      findAllStrings(curNode, s, result);
      return result;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      createTrie(products);
      vector<vector<string>> result;
      string prefix;
      for(char &c: searchWord) {
        prefix += c;
        result.push_back(searchTrie(prefix));
      }

      return result;
    }
};
