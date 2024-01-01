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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* front = head->next;
        ListNode* back = head;
            int temp = front->val;
            front->val = back->val;
            back->val = temp;
        while(front->next && front->next->next){

            front = front->next->next;
            back = back->next->next;
            int temp = front->val;
            front->val = back->val;
            back->val = temp;
        }
        return head;
    }
};