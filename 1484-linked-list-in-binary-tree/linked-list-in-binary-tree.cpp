/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head, TreeNode* root){
        if(!head) return 1;
        if(!root) return 0;
        if(head->val==root->val){
            return dfs(head->next , root->left) || dfs(head->next , root->right);
        }
        return 0;
    }

    bool inorder(ListNode* head, TreeNode* root){
        if(root && head){
            bool flag = 0;
            if(root->val==head->val){
                flag = dfs(head,root);
            }
            flag |= inorder(head,root->left);
            flag |= inorder(head,root->right);
            return flag;
        } 
        return 0;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return 1;
        if(!root) return 0;
        return inorder(head,root);
    }
};