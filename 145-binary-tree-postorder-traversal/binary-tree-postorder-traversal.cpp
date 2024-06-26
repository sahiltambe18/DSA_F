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
    void solve(vector<int> &v , TreeNode* root){
        if(root){
            solve(v,root->left);
            solve(v,root->right);
            v.push_back(root->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> v;
        solve(v,root);
        return v;
    }
};