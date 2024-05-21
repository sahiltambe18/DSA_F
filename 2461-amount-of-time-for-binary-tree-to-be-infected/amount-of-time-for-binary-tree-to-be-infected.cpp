/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void mapTree(unordered_map<int, TreeNode*>& mp, TreeNode* root, int target,
                 TreeNode*& targetNode) {
        if (target == root->val) {
            targetNode = root;
        }

        if (root->left) {
            mp[root->left->val] = root;
            mapTree(mp, root->left, target, targetNode);
        }
        if (root->right) {
            mp[root->right->val] = root;
            mapTree(mp, root->right, target, targetNode);
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        unordered_map<int , TreeNode*> mp;
        TreeNode* tNode = nullptr;
        mapTree(mp , root , start , tNode);
        
        
        queue<TreeNode*> q;
        set<int> st;
        
        q.push(tNode);
        st.insert(tNode->val);
        int count = -1;
        
        while(!q.empty()){
            int len = q.size();
            count++;
            
            while(len>0){
                len--;
                TreeNode* curr = q.front();
                q.pop();
                // st.insert(curr->val);
                
                if(curr->left && st.find(curr->left->val)==st.end()){
                    st.insert(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right && st.find(curr->right->val)==st.end()){
                    st.insert(curr->right->val);
                    q.push(curr->right);
                }
                
                if(mp.find(curr->val)!=mp.end()){
                    TreeNode* temp = mp[curr->val];
                    
                    if(st.find(temp->val)==st.end()){
                        st.insert(temp->val);
                        q.push(temp);
                    }
                }
                
                
            }
        }
        return count;
        
    }
};