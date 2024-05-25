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
    
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //lca will be between p ,q 
        // that means p<lca<q or p>lca>q
        
        while(1){

            int rootVal = root -> val, pVal = p -> val, qVal = q -> val;

            if(rootVal == pVal || rootVal == qVal){
                return root;
            }else if(rootVal < pVal && rootVal < qVal){
                root = root -> right;
            }else if(rootVal > pVal && rootVal > qVal){
                root = root -> left;
            }else{
                return root;
            }

        }
    }
};