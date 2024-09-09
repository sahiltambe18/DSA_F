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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m,vector<int>(n,-1));
        int l = 0 , r = n-1;
        int t = 0 , b = m-1;
        while(head){
            // left -> right top
            for(int i = l ; i <= r && head ; i++){
                v[t][i] = head->val;
                head = head->next;
            }
            t++;
            // top right -> bottom
            for(int i = t ; i <= b && head ; i++){
                v[i][r] = head->val;
                head = head->next;
            }
            r--;
            // bottom right -> left
            for(int i = r ; i >= l && head ; i--){
                v[b][i] = head->val;
                head = head->next;
            }
            b--;
            // bottom left -> top
            for(int i = b ; i >=t && head ;i--){
                v[i][l] = head->val;
                head = head->next;
            }
            l++;
        }
        return v;
    }
};