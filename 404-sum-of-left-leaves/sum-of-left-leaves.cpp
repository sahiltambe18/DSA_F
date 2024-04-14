/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root , bool flag){
        if(!root){
            return 0;
        }

        if(!root->left && !root->right){
            if(flag){
                return root->val + solve(root->left , true ) + solve(root->right , false); 
            }
        }

        return solve(root->left , true ) + solve(root->right , false); 
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root , false);
    }
};