/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode* head){
        ListNode* temp = head;
        int num = 0;
        while(temp){
            num++;
            temp = temp->next;
        }
        return num;
    }
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode* headA = l1;
        ListNode* headB = l2;

        int len1 = length(l1);
        int len2 = length(l2);

        // bring heads to same level
        if(len1>len2){
            while(len1>len2 ) {
                headA = headA->next;
                len1--;
            } 
        }else{
            while(len2>len1){
                headB = headB->next;
                len2--;
            }
        }

        // move both heads forward till null or they meet
        while(headA && headB){
            if(headA==headB) return headA;
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }

        return nullptr;
    }
};