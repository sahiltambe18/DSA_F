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
    int ans = 0;

    void inorder(TreeNode* root , int &maxLevel , int currLevel){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            if(maxLevel<currLevel){
                maxLevel = currLevel;
                ans = root->val;
                return ;
            }
        }

        inorder(root->left , maxLevel , currLevel+1);
        inorder(root->right , maxLevel , currLevel+1);

    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1;
        inorder(root , maxLevel , 0 );
        return ans;
    }
};