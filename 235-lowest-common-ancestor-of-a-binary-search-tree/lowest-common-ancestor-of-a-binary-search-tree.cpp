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
    vector<TreeNode*> ans;
    void solve(TreeNode* root ,TreeNode* p , vector<TreeNode*> &v){
        if(!root || ans.size()>0) return;
        if(root == p){
            v.push_back(root);
            ans = v;
            return;
        }
        v.push_back(root);
        solve(root->left,p,v);
        solve(root->right,p,v);
        v.pop_back();
    }
    bool answer = 0;
    void inorder(TreeNode* root,TreeNode* q){
        if(root){
            if(root==q){
                answer = true;
            }
            inorder(root->left,q);
            inorder(root->right,q);
        }
    }
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v;
        solve(root , p , v);
        for(int i = ans.size()-1 ; i>=0 ; i--){
            TreeNode* temp  = ans[i];
            inorder(temp,q);
            if(answer){
                return temp;
            }
        }
        return root;
        
    }
};