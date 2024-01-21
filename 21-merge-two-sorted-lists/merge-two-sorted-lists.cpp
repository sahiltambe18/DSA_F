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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if(!list1 && !list2){
        return list1;
    }
    else if(list1 && !list2){
        return list1;
    }else if(!list1 && list2){
        return list2;
    }
        ListNode* dummy = new ListNode(0);
        ListNode* hd = dummy;
        
        if(list1->val <= list2->val){
            dummy->next = list1;
            list1 = list1->next;
        }else{
            dummy->next = list2;
            list2 = list2->next;
        }

        hd= hd->next;
        while(list1 && list2){
            if(list1->val <= list2->val){
                hd->next = list1;
                list1 = list1->next;
            }else{
                hd->next = list2;
                list2 = list2->next;

            }
            hd= hd->next;
        }

        if(list1){
            hd->next = list1;
        }else if(list2){
            hd->next = list2;
        }
        return dummy->next;
    }
};