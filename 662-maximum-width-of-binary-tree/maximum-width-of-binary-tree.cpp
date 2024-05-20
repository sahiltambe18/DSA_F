

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

         long long maxi = 0;
        queue<pair<TreeNode*,  long long>> pq;
        pq.push({root, 0});

        while (!pq.empty()) {
            int size = pq.size();
             long long start = pq.front().second;  
             long long end = pq.back().second;   

            maxi = max(maxi, end - start + 1);

            for (int i = 0; i < size; i++) {
                pair<TreeNode*,  long long> node = pq.front();
                pq.pop();
                 long long idx = node.second - start;

                if (node.first->left) {
                    pq.push({node.first->left, 2 * idx });
                }
                if (node.first->right) {
                    pq.push({node.first->right, 2 * idx + 1});
                }
            }
        }

        return maxi;
    }
};
