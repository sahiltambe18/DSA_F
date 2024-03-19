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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* dummy = new ListNode(0,head);
        ListNode* temp = dummy;

        while(head){
            if(head->next && head->val==head->next->val){
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                head = head->next;
            }else{
                    temp->next = head;
                    temp = temp->next;
                    head = head->next;
            }
        }
        temp->next = nullptr;
        
        return dummy->next;
    }
};