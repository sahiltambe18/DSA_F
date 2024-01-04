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
    ListNode* sortList(ListNode* head) {
        ListNode *i = head;
        vector<int> v ;
        while(i){
            v.push_back(i->val);
            i = i->next;
        }
        sort(v.begin(),v.end());
        i = head;
        for(auto j : v){
            i->val = j;
            i = i->next; 
        }
        
        return head;
    }
};