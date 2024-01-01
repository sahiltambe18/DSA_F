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
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = length(head);
        k = k%len;

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* l = temp;
        ListNode* r = temp;
        for(int i = 0 ; i<k ; i++){
            if(!r->next){
                r = head;
            }else{
            r = r->next;
            }
        }
        //now l & r at k dist

        while(r->next){
            r = r->next;
            l = l->next;
        }
        r->next = head;
        head = l->next;
        l->next = nullptr;
        return head;
    }
};