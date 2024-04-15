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
    void solve(TreeNode* root , int &ans , int curr){
        

        curr = curr*10 + root->val;
        if(!root->left && !root->right){
            ans+= curr;
            return ;
        }
        if(root->left){
            solve(root->left , ans , curr);
        }
        if(root->right){
        solve(root->right , ans , curr);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root , ans , 0);
        return ans;
    }
};