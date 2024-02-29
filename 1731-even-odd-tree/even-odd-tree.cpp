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
    bool isEvenOddTree(TreeNode* root) {
        deque<TreeNode*> q0 , q1;
        bool odd = true;
        q0.push_back(root);
        int prev = INT_MIN;
        while(!q0.empty()){
            TreeNode* curr = q0.front();
            q0.pop_front();
            if(odd){
                // current value is > previous && odd
                if(curr->val > prev && curr->val%2==1){
                    prev = curr->val;
                    if(curr->left){
                        q1.push_back(curr->left);
                    }if(curr->right){
                        q1.push_back(curr->right);
                    }
                }else{
                    // not > prev || even
                    return false;
                }
            }else{
                // val < prev && even 
                if(curr->val < prev && curr->val%2==0){
                    prev = curr->val;
                    if(curr->left){
                        q1.push_back(curr->left);
                    }if(curr->right){
                        q1.push_back(curr->right);
                    }
                }else{
                    // not < prev || odd
                    return false;
                }
            }

            if(q0.empty()){
                q0 = q1;
                q1.clear();
                odd = !odd;
                prev = odd ? INT_MIN : INT_MAX;
            }

        }
        return true;
    }
};