/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* nod) {

        if(!nod) return nullptr;

        unordered_map<int,Node*> mp;
        
        queue<Node*> q;
        
        q.push(nod);

        while(!q.empty()){
            Node* fr = q.front();
            q.pop();

            if(mp.find(fr->val)==mp.end()){
                Node* node = new Node(fr->val);
                mp[fr->val] = node;
                for(auto i : fr->neighbors){
                    if(mp.find(i->val)==mp.end()){
                        q.push(i);
                    }
                }
            }
        }

        q.push(nod);
        set<int> st;
        while(!q.empty()){
            Node* nd = q.front();
            q.pop();

            st.insert(nd->val);

            for(auto node : nd->neighbors){
                mp[nd->val]->neighbors.push_back(mp[node->val]);
                if(st.find(node->val)==st.end()){
                    q.push(node);
                    st.insert(node->val);
                }
            }

        }

        return mp[nod->val];

    }
};