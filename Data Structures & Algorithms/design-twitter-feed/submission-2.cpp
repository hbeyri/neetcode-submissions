#include <ranges>

struct Tweet {
    int id, ts;
};

struct CompareTs {
    bool operator()(const Tweet& a, const Tweet& b) const {
        return a.ts > b.ts;   // smaller y = higher priority -> min-heap
    }
};

class Twitter {
public:

    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<Tweet>> tweets;
    int ts = 0;

    Twitter() = default;
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, ts++});
    }
    
    vector<int> getNewsFeed(int userId) {
        const unordered_set<int>& fids = followers[userId];
        vector<int> uids(fids.begin(), fids.end());
        uids.push_back(userId);
        priority_queue<Tweet, vector<Tweet>, CompareTs> pq; // min heap
        for(int uid : uids)
        {
            for(const Tweet& tweet : tweets[uid] | views::reverse)
            {
                if(pq.size()<10 || pq.top().ts < tweet.ts)
                {
                    pq.push(tweet);
                    if(pq.size() > 10)
                        pq.pop();
                }
                else
                    break;
            }
        }

        std::vector<int> ret;
        ret.resize(pq.size());
        for(int i=ret.size()-1;i>=0;--i)
        {
            ret[i] = pq.top().id;
            pq.pop();
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
