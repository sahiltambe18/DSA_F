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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        bool flag = true;
        if (!root) return ans;
        q.push_front(root);
        while (!q.empty()) {
            vector<int> level;
            int l = q.size();
            if (flag) {
                while (l > 0) {
                    TreeNode* curr = q.front();
                    q.pop_front();
                    level.push_back(curr->val);
                    if (curr->left)
                        q.push_back(curr->left);
                    if (curr->right)
                        q.push_back(curr->right);
                    l--;
                }
                flag = !flag;
            }else{
                while (l > 0) {
                    TreeNode* curr = q.back();
                    q.pop_back();
                    level.push_back(curr->val);
                    if (curr->right)
                        q.push_front(curr->right);
                    if (curr->left)
                        q.push_front(curr->left);
                    l--;
                }
                flag = !flag;
            }
            ans.push_back(level);
        }
        return ans;
    }
};