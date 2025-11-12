#include <bits/stdc++.h>
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
class Solution {
public:
    int res=0;
    void traversal(TreeNode* root, bool left=false) {
        if (root==nullptr) return;
        if (left && root->left==nullptr && root->right==nullptr) res+=root->val;
        traversal(root->right, left=false);
        traversal(root->left, left=true);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root);
        return res;
    }
};