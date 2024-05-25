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
    int succesor(TreeNode* root){
        if(!root) return -1;

        TreeNode* temp = root;
        while(temp->left){
            temp = temp->left;
        }
        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(key>root->val){
            root->right = deleteNode(root->right,key);
        }else if(key<root->val ){
            root->left  = deleteNode(root->left , key);
        }else{ // node found

            // case 1 : leaf node
            if(!root->left && !root->right){
                return nullptr;
            }

            // case 2 : has childs

            //subcases : has only left child
            if(root->left && !root->right){
                root = root->left;
            }else if(root->right && !root->left){
                root = root->right;
            }else{
                // both child present
                // i.e find inorder succesor of node
                int target = succesor(root->right);
                // replace key with succesor
                root->val = target;
                // call to delete succesor 
                root->right = deleteNode(root->right , target);
            }
        }
        return root;
    }
};