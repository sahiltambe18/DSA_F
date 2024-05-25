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
    void solve(TreeNode* root ,TreeNode* &tail ){
        if(!root->left && !root->right){
            tail = root;
            return ;
        }

        if(root->left){
            solve(root->left , tail);
        }

        TreeNode* right = nullptr;
        if(root->right){
            right = root->right;
        }
        if(tail){
            root->right = root->left;
            tail->right = right;
        }
        root->left = nullptr;
        if(right){
            tail = nullptr;
            solve(right , tail);
        }

    }
public:
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return;
        }
        TreeNode* tail = nullptr;
        solve(root,tail);
    }
};