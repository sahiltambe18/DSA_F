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
    int mx = 0;
    void inorder(TreeNode* root , int level , vector<int> &ans){
        if(!root){
            return ;
        }

        inorder(root->left , level+1,ans);
        
        
            ans[level] = root->val;
            mx = max(mx,level);
        
        inorder(root->right,level+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        
        vector<int> log(100) ,ans ;
        inorder(root , 0 , log);
        for(int i = 0 ; i <= mx ; i++ ){
            ans.push_back(log[i]);
        }
        return ans;
    }
};