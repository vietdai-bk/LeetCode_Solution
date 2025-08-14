#include <bits/stdc++.h>
using namespace std;
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1, st2;
        st1.push(p);
        st2.push(q);

        while (!st1.empty() && !st2.empty()) {
            TreeNode* n1 = st1.top(); st1.pop();
            TreeNode* n2 = st2.top(); st2.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;

            if (n1->val != n2->val) return false;

            st1.push(n1->right);
            st1.push(n1->left);
            st2.push(n2->right);
            st2.push(n2->left);
        }

        return st1.empty() && st2.empty();
    }
};
int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(1);
    Solution solve;
    bool isSame = solve.isSameTree(root1, root2);
    cout << isSame;
    return 0;
}