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
    TreeNode* find(TreeNode* root, int p, int q){
        if(!root || root->val== p || root->val == q){
            return root;
        }

        TreeNode* l = find(root->left , p , q);
        TreeNode* r = find(root->right , p , q);

        if(l&&r) return root;

        if(l){
            return l;
        }else{
            return r;
        }
        return nullptr;
    }

    string p1 = "";
    string p2 = "";

    void path(TreeNode* root ,  int s , int e , string &str){
        if(!root) return;
        if(root->val == s){
            p1 = str;
        }else if(root->val==e){
            p2 = str;
        } 
        if(p1.length()>0 && p2.length()>0) return;
        str.push_back('L');
        path(root->left , s, e , str );
        str.pop_back();
        str.push_back('R');
        path(root->right , s, e , str );
        str.pop_back();
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* commonNode = find(root, startValue , destValue);
        string str = "";
        path(commonNode , startValue , destValue , str);

        for(int i = 0 ; i < p1.length() ; i++){
            if(p1[i]=='L' || p1[i]=='R'){
                p1[i] = 'U';
            }
        }
        return p1+p2;
    }
};