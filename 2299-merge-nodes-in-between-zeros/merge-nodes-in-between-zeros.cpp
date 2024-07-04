/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
    [0,3,1,0,4,5,2,0]
     b       b

 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;
        int sum = 0;
        head = head->next;
        while(head){
            if(head->val==0){
                if(sum!=0){
                    dummy->next = new ListNode(sum);
                    dummy = dummy->next;
                }
                sum = 0;
            }else{
                sum += head->val;
            }
            head = head->next;
        }
        return newHead->next;
    }
};