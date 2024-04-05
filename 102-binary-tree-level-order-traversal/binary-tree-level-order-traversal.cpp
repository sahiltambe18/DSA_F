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
 **/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        //vector<int> level;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            while(n>0){
                TreeNode* curr = q.front(); 
                q.pop();
                // if(curr==NULL) return ans;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                level.push_back(curr->val);
                n--;
            }
            ans.push_back(level);
        }
        return ans;

    }
};