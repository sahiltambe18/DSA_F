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
    bool check(TreeNode* a , TreeNode* b){
        if(!a || !b){
            return a==b;
        }

        if(a->val == b->val){
            return check(a->left , b->right)&&check(a->right,b->left);
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return check(root->left , root->right);
    }
};