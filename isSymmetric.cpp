/* 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

输入：root = [1,2,2,3,4,4,3]
输出：true

输入：root = [1,2,2,null,3,null,3]
输出：false
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
    bool isSymmetric(TreeNode* root) {
        return isSame(root, root);
    }

    bool isSame(TreeNode* r1, TreeNode* r2)
    {
        if(r1 == NULL && r2 == NULL) 
            return true;
        if(!r1 || !r2) 
            return false;
        if(r1->val != r2->val) 
            return false;
        return isSame(r1->left, r2->right)
        &&isSame(r1->right, r2->left);
    }
};
