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
    ListNode* getNode(ListNode* head , int k){
        while(head && k>1){
            head = head->next;
            k--;
        }
        ListNode* ans = head->next;
        head->next = nullptr;
        return ans;
    }
    int length(ListNode* head){
        int l = 0;
        while(head){
            head=head->next;
            l++;
        }
        return l;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int l = length(head);
        int size = l / k;
        int rem = l%k;

        for(int i = 0 ; i < k && head ; i++){
            ans[i] = head;
            if(i<rem){
                head = getNode(head,size+1);
            }else{
                head = getNode(head , size);
            }
        }
        return ans;
    }
};