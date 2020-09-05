/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    TreeNode* reConstructBinaryTreeHelper(vector<int>& pre, int pre_start, int pre_end, 
                                          vector<int>& vin, int vin_start, int vin_end) {
        if(pre_start > pre_end || vin_start > vin_end)
            return nullptr;
        
        TreeNode* root = new TreeNode(pre[pre_start]);
        for(int i = vin_start; i <= vin_end; ++i) {
            if(pre[pre_start] == vin[i]) {
                root->left = reConstructBinaryTreeHelper(pre, pre_start + 1, 
                                                         i - vin_start + pre_start,
                                                        vin, vin_start, i - 1);
                
                root->right = reConstructBinaryTreeHelper(pre, i - vin_start + 
                                                          pre_start + 1, pre_end, 
                                                          vin, i + 1, vin_end);
                break;
            }
        }
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty() || pre.size() != vin.size())
            return nullptr;
        return reConstructBinaryTreeHelper(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};
