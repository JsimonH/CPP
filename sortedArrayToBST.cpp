/* 最小高度树
Given a sorted (increasing order) array with unique integer elements, write an algo­rithm to create a binary search tree with minimal height.

Example:
Given sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5]，which represents the following tree: 

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 
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
    TreeNode* dfs(const vector<int> &nums, int L, int R) {
        if(L > R) {
            return nullptr;
        }
        int mid = (L+R)>>1;
        auto ptr = new TreeNode(nums[mid]); //填充根节点
        ptr->left = dfs(nums, L, mid-1); //构造左子树
        ptr->right = dfs(nums, mid+1, R); //构造右子树
        return ptr;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};
