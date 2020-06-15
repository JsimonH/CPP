/* 二叉树的前序遍历(非递归)
Given a binary tree, return the preorder traversal of its nodes' values.
Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = st.top();
            st.pop();
            cur = top->right;
        }
        return res;
    }
};
