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
    ListNode* midd(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1 , ListNode* l2){
        ListNode* temp = new ListNode(0);
        ListNode* newHead = temp;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        temp->next = (l1==nullptr)?(l2):(l1);
        return newHead->next; 
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        // divide lists
        ListNode* leftHead = head;
        ListNode* mid = midd(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        // divide further recur
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        
        // it is what it is \U0001fae1
        return merge(leftHead , rightHead);
    }
};