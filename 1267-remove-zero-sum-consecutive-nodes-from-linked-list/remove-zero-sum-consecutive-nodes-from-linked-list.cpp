class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sumMap;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;

        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            sum += curr->val;
            sumMap[sum] = curr;
        }

        sum = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            sum += curr->val;
            curr->next = sumMap[sum]->next;
        }

        return dummy->next;
    }
};
