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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        vector<ListNode*> v;

        ListNode* temp = head;
        while(temp){
            if(st.empty() || st.top()->val>=temp->val){
                st.push(temp);
            }else{
                while(!st.empty() && st.top()->val<temp->val) st.pop();
                st.push(temp);
            }
            temp = temp->next;
        }
        head = nullptr;
        while(!st.empty()){
            temp = st.top();
            temp->next = head;
            head= temp;
            st.pop();
        }

        return head;

    }
};