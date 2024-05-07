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
    void solve(ListNode* head , int &carry){
        if(!head) return ;

        solve(head->next , carry);
        int val = (head->val*2)+carry;
        head->val = val%10;
        carry = val/10;
        // return head;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head , carry);
        if(carry>0){
            ListNode* dummy = new ListNode(carry , head);
            return dummy;
        }
        return head;
    }
};