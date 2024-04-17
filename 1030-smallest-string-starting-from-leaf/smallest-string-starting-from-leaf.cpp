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
    string solve(TreeNode* root , string s ){


         if(!root)
            return char(26+'a')+s;

        if(!root->left && !root->right)
            return char(root->val+'a')+s;
        
        string left=solve(root->left,char(root->val+'a')+s);
        string right=solve(root->right,char(root->val+'a')+s);
        
        return min(left,right);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        return solve(root , "" );
        
    }
};