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
    // bool flag = false;
    TreeNode* solve(TreeNode * root , int val , int depth , int currDepth){
        
        if(depth==1){
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            // curr-> = root;
            // root = curr;
            return curr;
        }
        if(!root ){
            return nullptr ;
        }

        if(currDepth==depth-1){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->left = root->left;
            root->left = l;
            r->right = root->right;
            root->right = r;
            // flag = true;
            return root;
        }
        solve(root->left , val , depth,currDepth+1);
        solve(root->right , val , depth ,currDepth+1);
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root , val , depth , 1);
        // return root;
    }
};