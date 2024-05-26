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
class BSTIterator {
public:
    vector<int> v;
    int i;

    void solve(TreeNode* root) {
        if (root) {
            solve(root->left);
            v.push_back(root->val);
            solve(root->right);
        }
    }

    BSTIterator(TreeNode* root) {
        solve(root);
        i = -1;
    }
    
    int next() {
        i++;
        return v[i];
    }
    
    bool hasNext() {
        if(i<0 && v.size()>0) return 1;
        return i < v.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */