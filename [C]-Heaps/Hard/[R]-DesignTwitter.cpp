/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
 

Constraints:

1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 104
All the tweets have unique IDs.
At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
A user cannot follow himself.
*/

class Twitter {
private:
    struct Tweet {
        int timestamp;
        int tweetId;
    };
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<Tweet>> tweets;

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        typedef tuple<int, int, int, int> T; // timestamp, tweetId, userId, index_in_tweetList
        priority_queue<T> pq;
        
        follows[userId].insert(userId); // Ensure self-follow

        // For each followed user, get their most recent tweet (if any)
        for (int followeeId : follows[userId]) {
            auto &tw = tweets[followeeId];
            int n = tw.size();
            if (n > 0)
                pq.emplace(tw[n-1].timestamp, tw[n-1].tweetId, followeeId, n-1);
        }
        
        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            auto [time, tweetId, userId, idx] = pq.top(); pq.pop();
            res.push_back(tweetId);

            // If this user has earlier tweets, push the next recent into heap
            if (idx-1 >= 0) {
                auto &tw = tweets[userId];
                pq.emplace(tw[idx-1].timestamp, tw[idx-1].tweetId, userId, idx-1);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        follows[followerId].erase(followeeId);
    }
};