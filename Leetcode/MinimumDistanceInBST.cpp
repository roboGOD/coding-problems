#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    int diff=-1;
    pair<int, int> helper(TreeNode* node) {
      if(node->left == nullptr && node->right == nullptr) {
        return pair(node->val, node-> val);
      }
      
      pair<int, int> lp, rp;
      int cdiff=-1;
      if(node->left != nullptr) {
        lp=helper(node->left);
        cdiff = abs(node->val - lp.second);
        if(diff == -1 || cdiff < diff) {
          diff = cdiff;
        }
      }
      
      if(node->right!=nullptr) {
        rp=helper(node->right);
        cdiff = abs(node->val - rp.first);
        if(diff == -1 || cdiff < diff) {
          diff = cdiff;
        }
      }
      
      if(node->left != nullptr && node->right != nullptr) {
        return pair(lp.first, rp.second);
      } else if(node->left != nullptr) {
        return pair(lp.first, node->val);
      } else if(node->right != nullptr) {
        return pair(node->val, rp.second);
      }

      return pair(node->val, node->val);
    }
  
    int minDiffInBST(TreeNode* root) {
      helper(root);
      return diff;
    }
};