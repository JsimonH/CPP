/* 二叉搜索树的第k大节点
给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4

示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
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
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || st.size()) 
        {
            while(cur) 
            {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            if(--k == 0) 
                return cur->val;
            cur = cur->left;
        }
        return root->val;
    }
};
