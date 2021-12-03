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

struct NodeLevel {
  TreeNode *node;
  int parentDepth;
  int depth;
  NodeLevel(TreeNode *node, int depth, int parentDepth) : node(node), parentDepth(parentDepth), depth(depth) {}
};

class Solution {
public:
  
    NodeLevel* helper(TreeNode* node, TreeNode* mparent, int depth) {
      if(node == nullptr) {
        return new NodeLevel(nullptr, depth-1, depth-1);
      }
      
      if(node->left == nullptr && node->right == nullptr) {
        if(mparent == nullptr) {
          return new NodeLevel(node, depth-1, depth-1);
        } else {
          return new NodeLevel(mparent, depth, mparent==node ? depth : depth-1);
        }
      }
      
      NodeLevel* ll = helper(node->left, node->right==nullptr ? node->left : node, depth+1);
      NodeLevel* lr = helper(node->right, node->left==nullptr ? node->right : node, depth+1);
      
      if(ll->node != nullptr && lr->node != nullptr) {
        if(ll->depth > lr->depth) {
          return ll;
        } else if(lr->depth > ll->depth) {
          return lr;
        } else {
          return new NodeLevel(node, ll->depth, depth);
        }
      } else if(ll->node != nullptr) {
        return ll;
      } else if(lr->node != nullptr) {
        return lr;
      } else {
        return ll;
      }
    }
  
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      NodeLevel* commonParent = helper(root, nullptr, 0);

      return commonParent->node;
    }
};