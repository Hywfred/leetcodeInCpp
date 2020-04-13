//
// Created by Hywfred on 2020/4/13.
//
// 失败的案例
#ifndef LEETCODEINCPP_DESIGNTWITTEROPT_H
#define LEETCODEINCPP_DESIGNTWITTEROPT_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Time {
public:
    static int time;
};
int Time::time = 0;

class Tweet {
public:
    Tweet(int id, int time) : m_tweetId(id), m_pubTime(time) {}

    int getTweetId() const {
        return m_tweetId;
    }

    int getPubTime() const {
        return m_pubTime;
    }
private:
    int m_tweetId;
    int m_pubTime;
};

class User {
public:
    User(int id) : m_userId(id) {}
    // 关注用户
    void follow(const int userId) {
        if (userId == m_userId) return;
        m_follows.insert(userId);
    }
    // 取关用户
    void unFollow(const int userId) {
        m_follows.erase(userId);
    }
    // 获取用户 id
    int getId() const {
        return m_userId;
    }
    // 发布推文
    void pubTweet(const int tweetsId) {
        ++Time::time;
        m_tweets.push_back(Tweet(tweetsId, Time::time));
    }
    // 获取推文
    vector<Tweet> getTweets() const {
        return m_tweets;
    }
    // 获取关注用户
    unordered_set<int> getFollowees() const {
        return m_follows;
    }
private:
    int m_userId;
    vector<Tweet> m_tweets;
    unordered_set<int> m_follows;
};

struct CmpTweet {
    bool operator()(const Tweet &t1, const Tweet &t2) {
        return t1.getPubTime() < t2.getPubTime();
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto it = m_users.find(userId);
        if (it == m_users.end()) {
            auto user = User(userId);
            user.pubTweet(tweetId);
            m_users.insert(make_pair(userId, user));
        } else {
            it->second.pubTweet(tweetId);
        }

    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        auto it = m_users.find(userId);
        if (it == m_users.end()) {
            return ans;
        }
        auto user = it->second;
        auto followees = user.getFollowees();
        for (auto elem : user.getTweets()) {
            m_tweets.push(elem);
        }
        for (auto followeeId : followees) {
            auto it = m_users.find(followeeId);
            if (it == m_users.end()) {
                continue;
            }
            auto followee = it->second;
            for (auto elem : followee.getTweets()) {
                m_tweets.push(elem);
            }
        }
        int count = 0;
        while (!m_tweets.empty()) {
            ans.push_back(m_tweets.top().getTweetId());
            m_tweets.pop();
            ++count;
            if (count >= 10) break;
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto it = m_users.find(followerId);
        if (it== m_users.end()) {
            auto user = User(followerId);
            m_users.insert(make_pair(followerId, user));
        }
        it = m_users.find(followerId);
        it->second.follow(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto it = m_users.find(followerId);
        if (it== m_users.end()) {
            return;
        }
        it->second.unFollow(followeeId);
    }

private:
    unordered_map<int, User> m_users;
    priority_queue<Tweet, vector<Tweet>, CmpTweet> m_tweets;
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

void TestTweet() {
    Twitter *twitter = new Twitter();
    vector<string> cmd {"postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","follow","follow","follow","follow","follow","follow","follow","follow","follow","follow","follow","follow","getNewsFeed","getNewsFeed","getNewsFeed","getNewsFeed","getNewsFeed"};
    vector<vector<int>> data{{1,6765},{5,671},{3,2868},{4,8148},{4,386},{3,6673},{3,7946},{3,1445},{4,4822},{1,3781},{4,9038},{1,9643},{3,5917},{2,8847},{1,3},{1,4},{4,2},{4,1},{3,2},{3,5},{3,1},{2,3},{2,1},{2,5},{5,1},{5,2},{1},{2},{3},{4},{5}};
    cmd = {"postTweet","getNewsFeed","follow","getNewsFeed","unfollow","getNewsFeed"};
    data = {{1,1},{1},{2,1},{2},{2,1},{2}};
    cmd = {"postTweet","follow","getNewsFeed"};
    data = {{1,5},{1,1},{1}};
    cmd = {"postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed","follow","getNewsFeed","unfollow","getNewsFeed"};
    data = {{1,5},{2,3},{1,101},{2,13},{2,10},{1,2},{1,94},{2,505},{1,333},{2,22},{1,11},{1,205},{2,203},{1,201},{2,213},{1,200},{2,202},{1,204},{2,208},{2,233},{1,222},{2,211},{1},{1,2},{1},{1,2},{1}};
    vector<int> ans;
    for (int i = 0; i < cmd.size(); ++i) {
        if (cmd[i] == "postTweet") {
            twitter->postTweet(data[i][0], data[i][1]);
            cout << "null" << ",";
        } else if (cmd[i] == "follow") {
            twitter->follow(data[i][0], data[i][1]);
            cout << "null" << ",";
        } else if (cmd[i] == "unfollow") {
            twitter->unfollow(data[i][0], data[i][1]);
            cout << "null" << ",";
        } else if (cmd[i] == "getNewsFeed") {
            ans = twitter->getNewsFeed(data[i][0]);
            cout << "{";
            for (auto elem : ans) {
                cout << elem << ",";
            }
            cout << "],";
        }
    }
}

#endif //LEETCODEINCPP_DESIGNTWITTEROPT_H
