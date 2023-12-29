/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        if(!node || !node->next){
            return;
        }

        ListNode* temp = node->next;
        
            node->val = temp->val;
            node->next = temp->next;
        
        delete temp;
    }
};