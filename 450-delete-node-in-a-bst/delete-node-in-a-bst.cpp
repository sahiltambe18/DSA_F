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
    int successor(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left) {
            temp = temp->left;
        }
        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            // Node found
            if (!root->left && !root->right) {
                // Case 1: Leaf node
                delete root;
                return nullptr;
            } else if (root->left && !root->right) {
                // Case 2a: Only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else if (!root->left && root->right) {
                // Case 2b: Only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else {
                // Case 3: Both children present
                int target = successor(root->right);
                root->val = target;
                root->right = deleteNode(root->right, target);
            }
        }
        return root;
    }
};