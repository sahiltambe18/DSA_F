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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0 ){
            return head;
        }

        int n = 1;
        ListNode* ptr = head;
        while(ptr->next!=nullptr){
            n++;
            ptr = ptr->next;
        }

        ptr->next = head;
        k = k%n;
        if(k==0){
        ptr->next = nullptr;
            return head;
        }
        ptr = head;
        while(n-1>k){
            ptr = ptr->next;
            n--;
        }
        ListNode* newHead = ptr->next;
        ptr->next = nullptr;

        // ptr = newHead;
        // while(ptr->next!=nullptr){
        //     ptr = ptr->next;
        // }
        // ptr->next = head;
        return newHead;
    }
};