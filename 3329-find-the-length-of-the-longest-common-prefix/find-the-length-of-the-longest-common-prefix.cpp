
struct Node {
    Node* ref[10];
    bool flag;
    Node() { 
        flag = 0;
        for(int i = 0 ; i < 10 ; i++) ref[i] = nullptr;
    }
    bool check(char c) { 
        return ref[c - '0'] != nullptr; 
    }
    void put(char c, Node* node) { 
        ref[c - '0'] = node; 
    }
    Node* getNext(char c) { 
        return ref[c - '0']; 
    }
    void markAsEnd() { 
        flag = true; 
    }
};

class Trie {
    Node* root;

public:
    Trie() { 
        root = new Node(); 
    }
    void insert(string str) {
        Node* temp = root;
        for (char c : str) {
            if (!temp->check(c)) {
                temp->put(c, new Node());
            }
            temp = temp->getNext(c);
        }
        temp->markAsEnd();
    }
    bool search(string s) {
        Node* node = root;
        for (int i = 0; i < s.length(); i++) {
            if (!node->check(s[i])) {
                return 0;
            }
            node = node->getNext(s[i]);
        }
        return node->flag == 1;
    }

    bool pref(string s) {
        Node* node = root;
        for (int i = 0; i < s.length(); i++) {
            if (!node->check(s[i])) {
                return 0;
            }
            node = node->getNext(s[i]);
        }
        return 1;
    }
};

class Solution {

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(int i = 0 ; i < arr1.size() ; i++){
            t.insert(to_string(arr1[i]));
        }
        int ans = 0;
        for(int i = 0 ; i < arr2.size() ; i++){
            string s = to_string(arr2[i]);
            for(int j = 1 ; j <= s.length() ; j++){
                if(t.pref(s.substr(0,j))){
                    ans = max(ans, j);
                }
            }
        }

        return ans;

    }
};