/* 合法二叉搜索树
Implement a function to check if a binary tree is a binary search tree.

Example 1:
Input:
    2
   / \
  1   3
Output: true

Example 2:
Input:
    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: Input: [5,1,4,null,null,3,6].
     the value of root node is 5, but its right child has value 4.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> ans;
    void visit(TreeNode* root) {
        ans.push_back(root->val);
    }
    void dfs(TreeNode* root) {
        if (root != NULL) {
            dfs(root->left);
            visit(root);
            dfs(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        dfs(root);
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i + 1] <= ans[i])
                return false;
        }
        return true;
    }
};
