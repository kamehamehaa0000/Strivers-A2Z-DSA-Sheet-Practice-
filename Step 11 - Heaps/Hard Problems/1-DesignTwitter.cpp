#include <bits/stdc++.h>
using namespace std;
class Twitter
{
public:
    unordered_map<int, set<int>> friends; // follower : followee
    int curr = 0;
    priority_queue<vector<int>> timeline;
    Twitter()
    {
        friends.clear();
        curr = 0;
        timeline = priority_queue<vector<int>>();
    }

    void postTweet(int userId, int tweetId)
    {
        timeline.push({curr++, tweetId, userId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        priority_queue<vector<int>> userTimeline = timeline;
        int n = 0;

        while (!userTimeline.empty() && n < 10)
        {
            vector<int> topTweet = userTimeline.top();
            userTimeline.pop();
            if (topTweet[2] == userId || friends[userId].count(topTweet[2]))
            {
                ans.push_back(topTweet[1]);
                n++;
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        friends[followerId].erase(followeeId);
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