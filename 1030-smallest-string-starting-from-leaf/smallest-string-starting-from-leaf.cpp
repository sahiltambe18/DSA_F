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
    void solve(TreeNode* root , string temp , string &ans){
        
        char c = 'a'+root->val;
        temp = c + temp;
        if(!root->right && !root->left){
            if( ans=="" || ans>temp){
                ans = temp;
            }
            return ;
        }
        if(root->left) {
            solve(root->left , temp , ans);
        }
        if(root->right){
            solve(root->right , temp , ans);
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        solve(root , "" , ans);
        return ans;
    }
};