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
    void inorder(TreeNode* root ,vector<int> &v){
        if(root){
            inorder(root->left , v);
            v.push_back(root->val);        
            inorder(root->right , v);
        }
    }

    TreeNode* construct(vector<int> &v , int s , int e){
        if(s<0 || e>=v.size() || s>e ) return nullptr;

        int mid = s + (e-s)/2;

        TreeNode* root = new TreeNode(v[mid]);
        root->left = construct(v , s , mid-1);
        root->right = construct(v , mid+1 , e);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root , v);

        return construct(v, 0 , v.size()-1);

    }
};