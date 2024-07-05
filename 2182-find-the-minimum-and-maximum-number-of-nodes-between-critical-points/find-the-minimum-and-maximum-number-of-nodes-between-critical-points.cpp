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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 0;
        // vector<int> points;

        int fst = -1 , lst = -1;

        int minD = INT_MAX;
        int maxD = INT_MIN;
        int prev = -1  , curr , nxt = -1;

        while(head->next){
            curr = head->val;
            nxt = head->next->val;
            if(prev!=-1){
                if(curr > prev && curr > nxt){
                    if(fst == -1){
                        fst = idx;
                    }
                    if(fst!=idx){
                        minD = min(minD , idx - lst);
                    }
                    lst = idx;
                }else if(curr<prev && curr < nxt){
                    if(fst==-1){
                        fst = idx;
                    }
                    if(fst!=idx){
                        minD = min(minD , idx - lst);
                    }
                    lst = idx;
                }
            }
            prev = curr;
            head = head->next;
            idx++;
        }

        if(fst != lst && minD != INT_MAX){
            maxD = lst-fst;
            return {minD,maxD};
        }
        return {-1,-1};
    }
};