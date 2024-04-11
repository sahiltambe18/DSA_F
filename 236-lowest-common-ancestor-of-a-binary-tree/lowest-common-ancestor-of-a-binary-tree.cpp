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
    void findPath(TreeNode* root , TreeNode* target, vector<TreeNode*> &temp  , vector<TreeNode*> &v){
        if(!root || !v.empty()){
            return;
        }

        if(root==target){
            v = temp;
            v.push_back(root);
            return ;
        }

        temp.push_back(root);
        findPath(root->left,target , temp ,v);
        findPath(root->right,target , temp ,v);
        temp.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1 , p2 , temp;

        findPath(root , p , temp , p1);
        findPath(root , q , temp , p2);

        int n = p1.size();
        int l = p2.size();

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = l-1 ; j>=0 ; j--){
                if(p1[i]==p2[j]){
                    return p1[i];
                }
            }
        }

        return nullptr;

    }
};