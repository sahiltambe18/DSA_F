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
    int depth = 0;
    void solve(TreeNode* root , int l){
        
        depth = max(depth,l);
            
        if(root->left) solve(root->left , l+1);
        if(root->right) solve(root->right , l+1);
        
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        solve(root,1);
        return depth;
    }
};