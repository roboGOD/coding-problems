#include<bits/stdc++.h>
using namespace std;

struct Node {
  bool isWord=false;
  vector<Node *> m;

  Node(): m(26, nullptr) {}
} *root, *cur;


class Trie {
  public:

  Trie() {
    root=new Node();
  }

  void insert(string &word) {
    cur=root;
    for(char &c: word) {
      if(cur->m[c-'a'] == nullptr) {
        cur->m[c-'a'] = new Node();
      }
      cur=cur->m[c-'a'];
    }
    cur->isWord = true;
  }
};

class Solution {
public:
  string getReplacement(string &s) {
    cur=root;
    string word="";
    for(char &c: s) {
      word += c;
      if(cur->m[c-'a'] == nullptr) {
        return s;
      } else if(cur->m[c-'a']->isWord) {
        return word;
      } 

      cur=cur->m[c-'a'];
    }
    return s;
  }

  string replaceWords(vector<string>& dictionary, string sentence) {
    Trie t=Trie();
    for(string &word: dictionary) {
      t.insert(word);
    }

    string word = "";
    string result = "";
    for (char &x : sentence) {
      if (x == ' ' && word != "") {
        result += getReplacement(word) + ' ';
        word = "";
      } else {
        word = word + x;
      }
    }

    if(word != "") {
      result += getReplacement(word);
    }

    return result;
  }
};