/* 二叉树的镜像
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
*/

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
