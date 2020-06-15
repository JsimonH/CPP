/* 二叉树的中序遍历(非递归)
Given a binary tree, return the inorder traversal of its nodes' values.
Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = st.top();
            res.push_back(top->val);
            st.pop();
            cur = top->right;
        }
        return res;
    }
};
