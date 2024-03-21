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
    int gcd(int x , int y){
        for(int i = min(x,y) ; i>1 ; i--){
            if(x%i==0 && y%i==0) return i;
        }
        return 1;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        int curr = head->val;
        int nxt = head->next->val;

        ListNode* temp = head;

        while(temp->next){
            curr = temp->val;
            nxt = temp->next->val;
            /// change
            //ListNode* nxtNode = temp->next;
            temp->next = new ListNode(gcd(curr , nxt) , temp->next);
            temp = temp->next->next;
        }
        return head;
    }
};