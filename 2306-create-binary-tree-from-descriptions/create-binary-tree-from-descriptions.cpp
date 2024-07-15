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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mp;
        unordered_set<int> st;
        for(auto v : descriptions){
            if(mp.find(v[0])==mp.end()){
                mp[v[0]] =  new TreeNode(v[0]);
            } if(mp.find(v[1])==mp.end()){
                mp[v[1]] =  new TreeNode(v[1]);
            }

            if(v[2]){
                mp[v[0]]->left = mp[v[1]];
            }else{
                mp[v[0]]->right = mp[v[1]];
            }
            st.insert(v[1]);
        }
        TreeNode* root = nullptr;
        root = mp[descriptions[0][0]];
        for(auto i : descriptions)
        {
            int parent = i[0];
            if(st.find(parent)==st.end()){
                root = mp[parent];
                break;
            }
        }
        return root;

    }
};