struct Node{
    Node* ref[26] = {nullptr};
    int end;
    Node(){
        end = 0;
    }
    void addEnd(){
        end++;
    }
    bool check(char c){
        return ref[c-'a']!=nullptr;
    }
    void addNode(char c){
        ref[c-'a'] = new Node();
    }
    Node* get(char c){
        return ref[c-'a'];
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* temp = root;
        for(int i = 0 ; i < s.length() ;i++){
            temp->addEnd();
            if(!temp->check(s[i])){
                temp->addNode(s[i]);
            }
            temp = temp->get(s[i]);
        }
        temp->addEnd();
    }
    int getScore(string s){
        Node* temp = root;
        int score = 0;
        for(int i = 0 ; i < s.length();i++){
            temp = temp->get(s[i]);
            score+= temp->end; 
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        int n = words.size();
        for(auto &i : words){
            t.insert(i);
        }
        vector<int> ans(n);
        for(int i = 0 ; i < n ;i++){
            ans[i] = t.getScore(words[i]);
        }
        return ans;
    }
};