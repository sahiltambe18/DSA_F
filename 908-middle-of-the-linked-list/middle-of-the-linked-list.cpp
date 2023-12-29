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
    ListNode* middleNode(ListNode* head) {
        bool count = 0;
        ListNode* temp = head->next;

        while(temp){
            count = !count;
            if(count){
                head = head->next;
            }
            temp = temp->next;
        }
        return head;
    }
};