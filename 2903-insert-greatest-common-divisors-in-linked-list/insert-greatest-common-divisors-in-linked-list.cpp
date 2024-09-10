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
        ListNode* temp = head;
        while (temp->next) {
            int a = temp->val;
            int b = temp->next->val;
            int g = gcd(a, b);
            ListNode* n = new ListNode(g);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }
        return head;
    }
};