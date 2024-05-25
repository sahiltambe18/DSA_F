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
    int cnt = 0;

public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        int num =  kthSmallest(root->left , k);
        cnt++;
        if(cnt==k){
            return root->val;
        }
        if(num==-1){
            num =  kthSmallest(root->right , k);
        }
        return num;
    }
};