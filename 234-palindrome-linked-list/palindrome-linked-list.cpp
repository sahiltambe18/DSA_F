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
    bool check(string a){
        int l = 0 , r = a.length()-1;
        while(l<=r){
            if(a[l]!=a[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        string ans = "";
        while(head){
            char ch = '0' + head->val;
            ans+=ch;
            head = head->next;
        }
        return check(ans);
    }
};