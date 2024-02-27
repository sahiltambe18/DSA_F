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
    int bk(TreeNode* root , int &res){
        if(root){
            int l = bk(root->left , res);
            int r = bk(root->right , res);

            res = max(res , l+r);
            return max(l,r)+1;
        }
        return 0;
    } 
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        bk(root , d);

        return d;

    }
};