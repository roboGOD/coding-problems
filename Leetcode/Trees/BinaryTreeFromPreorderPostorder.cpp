#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  unordered_map<int, TreeNode*> nodes;
  unordered_map<int, TreeNode*> parents;

  TreeNode* findParentNode(TreeNode* cur) {
    if(cur == nullptr) {
      return nullptr;
    }
    if(cur->left == nullptr || cur->right == nullptr) {
      return cur;
    } else {
      return findParentNode(parents[cur->val]);
    }
  }

  TreeNode* findNode(TreeNode* cur, int val) {
    if(cur == nullptr) {
      return nullptr;
    }
    if(cur->val == val) {
      return findParentNode(parents[cur->val]);
    } else {
      return findNode(parents[cur->val], val);
    }
  }

  TreeNode* addNode(TreeNode* cur, int val) {
    TreeNode* node = new TreeNode(val);
    if(cur != nullptr) {
      if(cur->left == nullptr) {
        cur->left = node;
        return node;
      } else if(cur->right == nullptr) {
        cur->right = node;
        return node;
      }
    }

    return nullptr;
  }

  string getNodeVal(TreeNode* cur) {
    if(cur == nullptr) {
      return "nullptr";
    } else {
      return to_string(cur->val);
    }
  }

  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    nodes.clear();
    parents.clear();
    TreeNode* root = nullptr;
    TreeNode* cur = nullptr;
    int n = postorder.size();
    int ci, cj;
    int i=0,j=0;

    for(i=0; i<n; i++) {
      ci = postorder[i];

      if(nodes[ci] == nullptr) {
        while (j < n) {
          cj = preorder[j];
          
          if(cur == nullptr && root == nullptr) {
            root = new TreeNode(cj);
            cur = root;
            nodes.insert({cj, root});
            parents.insert({cj, nullptr});
          } else {
            parents.insert({cj, cur});
            cur = addNode(cur, cj);
            nodes.insert({cj, cur});
          }
          
          j++;
            
          // cout << "Added " << cur-> val << " Child of " << getNodeVal(parents[cur->val]) << endl;

          if(cj == ci) {
            cur = parents[cur->val];
            // cout << "BREAK " << ci << " Parent is " << getNodeVal(cur) << endl;
            break;
          }
        }

        cur = findParentNode(cur);
        // cout << "findParentNode " << getNodeVal(cur) << endl;
      } else {
        // cout << "Already Visited " << ci << " current is " << getNodeVal(cur) << endl;
        TreeNode* temp = findNode(cur, ci);
        if(temp != nullptr) {
          cur = temp;
        } else {
          cur = findParentNode(cur);
        }
        // cout << "Already Visited " << ci << " new current is " << getNodeVal(cur) << endl;
      }

      if(cur == nullptr) {
        return root;
      }
    }

    return root;
  }
};