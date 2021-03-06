/* 根据二叉树创建字符串
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that 
don't affect the one-to-one mapping relationship between the string and the original binary tree.

Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     
Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".  */

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
    string tree2str(TreeNode* t) {
        string str; 
        if(t == nullptr)
            return str;
        
        str += to_string(t->val);
        if(t->left)
        {
            str += '(';
            str += tree2str(t->left);
            str += ')';
        }
        else if(t->right)
        {
            str += "()";
        }
        if(t->right)
        {
            str += '(';
            str += tree2str(t->right);
            str += ')';
        }
        return str;
    }
};
