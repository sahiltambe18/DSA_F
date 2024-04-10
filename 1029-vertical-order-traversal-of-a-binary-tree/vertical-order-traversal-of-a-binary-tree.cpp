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

/*
use this
map<int,map<int,multiset<int>>> m;
*/
class Solution {
    int minCol = INT_MAX;
    int maxCol = INT_MIN;
    int maxRow = INT_MIN;

    void traverse(unordered_map<int, unordered_map<int, multiset<int>>>& mp,
                  TreeNode* root, int row, int col) {
        if (!root) {
            maxRow = max(row - 1, maxRow);
            return;
        }
        minCol = min(col, minCol);
        maxCol = max(maxCol, col);
        traverse(mp, root->left, row + 1, col - 1);
        mp[col][row].insert(root->val);
        traverse(mp, root->right, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int, unordered_map<int, multiset<int>>> mp;
        traverse(mp, root, 0, 0);
        for (int i = minCol; i <= maxCol; i++) {
            vector<int> v;
            for (int j = 0; j <= maxRow; j++) {
                if (mp.find(i) != mp.end() && mp[i].find(j) != mp[i].end()) {
                    for (auto k : mp[i][j]) {
                        v.push_back(k);
                    }
                }
            }
            if (!v.empty()) {
                ans.push_back(v);
            }
        }

        return ans;
    }
};
