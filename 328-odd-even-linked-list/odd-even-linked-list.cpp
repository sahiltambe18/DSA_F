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
    ListNode* oddEvenList(ListNode* head) {

        if(!head || !head->next) return head;
        
        bool flag = 1;

        ListNode* start = new ListNode(0);
        ListNode* tail = start;
        
        
        ListNode* nxt = new ListNode(0);
        ListNode* tail2 = nxt;
        
        while(head){
            if(flag){
                tail->next = new ListNode(head->val);
                tail = tail->next;
            }else{
                tail2->next = new ListNode(head->val);
                tail2 = tail2->next;
            }
            flag = !flag;
            head = head->next;
        }
        tail->next = nxt->next;
        delete nxt;
        
        return start->next;
    }
};