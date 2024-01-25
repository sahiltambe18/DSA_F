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
    ListNode* merge( ListNode* l1 , ListNode* l2){
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if(l1){
            temp->next = l1;
        }else{
            temp->next = l2;
        }
        return ans->next;
    } 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* ans = lists[0];
        for(int i = 1 ; i < lists.size() ; i++){
            ans = merge(ans , lists[i]);
        }
        return ans;
    }
};