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
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        // int curr = head->val;
        // int nxt = head->next->val;

        ListNode* temp = head;

        while(temp->next){
            // curr = temp->val;
            // nxt = temp->next->val;
            /// change
            //ListNode* nxtNode = temp->next;
            temp->next = new ListNode(gcd(temp->val , temp->next->val) , temp->next);
            temp = temp->next->next;
        }
        return head;
    }
};