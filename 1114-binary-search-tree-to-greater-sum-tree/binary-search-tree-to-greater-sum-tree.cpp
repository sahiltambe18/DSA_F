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
    void revInorder(TreeNode* root , int &prev){
        if(root){
            revInorder(root->right,prev);
            prev+= root->val;
            root->val = prev;
            revInorder(root->left, prev);
        }
        // return prev;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int a = 0;
        revInorder(root,a);
        return root;
    }
};