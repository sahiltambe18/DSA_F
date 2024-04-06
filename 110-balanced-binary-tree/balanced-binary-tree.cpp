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
    bool flag = true;
    int solve(TreeNode* root ){
        if(!root ){
            return 0;
        }
        int l = solve(root->left )+1;
        int r = solve(root->right )+1;
        int diff = abs(l-r);
        if(diff>1){
            flag = false;
        }
        return max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
         solve(root);
        // if(d>1){
        //     return false;
        // }
        return flag ;
    }
};