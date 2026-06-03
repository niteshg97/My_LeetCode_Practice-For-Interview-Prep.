class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> following;
    // userId -> {(time, tweetId)}
    unordered_map<int, vector<pair<int,int>>> tweets;
public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        // user follows himself
        following[userId].insert(userId);
        for (int followee : following[userId]) {
            auto &userTweets = tweets[followee];
            if (!userTweets.empty()) {
                int idx = userTweets.size() - 1;
                pq.push({
                    userTweets[idx].first,   // timestamp
                    userTweets[idx].second,  // tweetId
                    followee,                // user
                    idx                      // index in vector
                });
            }
        }
        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {

            auto top = pq.top();
            pq.pop();

            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];
            feed.push_back(tweetId);
            idx--;
            if (idx >= 0) {
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }
        return feed;
    }
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        following[followerId].erase(followeeId);
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