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
    void solve(ListNode* &prev , ListNode* &curr , ListNode* &nxt){
        if(!curr) return ;
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        solve(prev , curr , nxt);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        solve(prev , curr , nxt);
        return prev;
    }
};