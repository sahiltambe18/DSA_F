/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void mapTree(unordered_map<int,TreeNode*> &mp , TreeNode* root){
        //if(!root) return;

        if(root->left){
            mapTree(mp , root->left);
            mp[root->left->val] = root;
        }
        if(root->right){
            mapTree(mp , root->right);
            mp[root->right->val] = root;
        }
    } 
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,TreeNode*> mp;
        mapTree(mp , root);

        vector<int> ans;

        queue<TreeNode*> q;
        set<int> st;

        q.push(target);

            st.insert(target->val);
            k++;
        while(!q.empty() && k>0){
            int l = q.size();
            k--;
            if(k==0){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            while(l>0){
                l--;
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && st.find(temp->left->val)==st.end()){
                    st.insert(temp->left->val);
                    q.push(temp->left);
                }
                if(temp->right && st.find(temp->right->val)==st.end()){
                    st.insert(temp->right->val);
                    q.push(temp->right);
                }
                if(mp.find(temp->val)!=mp.end() ){
                    TreeNode* parent = mp[temp->val];
                    if(st.find(parent->val)==st.end()){
                        st.insert(parent->val);
                        q.push(parent);
                    }
                }
            }
        }
        return ans;
    }
};