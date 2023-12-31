/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> mp;
        while(head){
            if(mp.find(head)!=mp.end()){
                return head;
            }
            mp[head] = 1;
            head = head->next;
        }
        return nullptr;
    }
};