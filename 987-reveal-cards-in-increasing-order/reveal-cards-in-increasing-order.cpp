class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(),deck.end());
        
        deque<int> dq;
        dq.push_front(deck[n-1]);
        for(int i = n-2 ; i >=0 ;i--){
            int ele = dq.back();
            dq.pop_back();
            dq.push_front(ele);
            dq.push_front(deck[i]);
        }
        for(int i = 0 ; i <n;i++){
            deck[i] = dq.front();
            dq.pop_front();
        }
        return deck;
    }
};