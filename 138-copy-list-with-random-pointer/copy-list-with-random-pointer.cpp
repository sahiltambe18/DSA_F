/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* dummy = new Node(0);
        Node* temp2 = dummy;
        Node* temp = head;
        map<Node* , Node*> mp;
        while(temp){
            temp2->next = new Node(temp->val);
            temp2 = temp2->next;
            mp[temp] = temp2;
            temp = temp->next;
        }
        temp = head;
        while(temp){
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return dummy->next;
    }
};