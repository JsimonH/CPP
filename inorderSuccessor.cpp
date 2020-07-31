/* 后继者
Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.
Return null if there's no "next" node for the given node.

Example 1:
Input: root = [2,1,3], p = 1

  2
 / \
1   3

Output: 2

Example 2:
Input: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

Output: null
*/

//递归
class Solution1 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) 
            return NULL;
        if (p->val >= root->val) {
            return inorderSuccessor(root->right, p);
        } 
        else {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};

//非递归
class Solution2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            p = p->right;
            while (p->left) p = p->left;
            return p;
        }
        TreeNode* res = NULL;
        while (root != p) {
            if (root->val < p->val) {
                root = root->right;
            } 
            else {
                res = root;
                root = root->left;
            }
        }
        return res;
    }
};
