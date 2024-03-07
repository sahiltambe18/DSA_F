class Twitter {
    map<int, set<int>> followingOf; // user -> his following
    map<int , vector<pair<int,int>>> tweets; // user -> his tweets <time , tweet>
    int time = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        
        for(auto tw : tweets[userId]){
                pq.push(tw);
            }

        for(auto st : followingOf[userId] ){
            for(auto tw : tweets[st]){
                pq.push(tw);
            }
        }
        int count = 0;
        while(!pq.empty() && count<10){
            ans.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followingOf[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingOf[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */