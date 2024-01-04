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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        else if( !head->next){
            return nullptr;
        }
        ListNode *dummy = new ListNode(0 , head);
        ListNode *slow = head , *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            dummy = slow;
            slow = slow->next;
        }
        dummy->next = slow->next;
        delete slow;
        return head;
    }
};