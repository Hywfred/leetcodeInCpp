//
// Created by Hywfred on 2020/4/13.
//
//设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
//postTweet(userId, tweetId): 创建一条新的推文
//getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
//follow(followerId, followeeId): 关注一个用户
//unfollow(followerId, followeeId): 取消关注一个用户
//示例:
//Twitter twitter = new Twitter();
//// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
//twitter.postTweet(1, 5);
//// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
//twitter.getNewsFeed(1);
//// 用户1关注了用户2.
//twitter.follow(1, 2);
//// 用户2发送了一个新推文 (推文id = 6).
//twitter.postTweet(2, 6);
//// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
//// 推文id6应当在推文id5之前，因为它是在5之后发送的.
//twitter.getNewsFeed(1);
//// 用户1取消关注了用户2.
//twitter.unfollow(1, 2);
//// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
//// 因为用户1已经不再关注用户2.
//twitter.getNewsFeed(1);
#ifndef LEETCODEINCPP_DESIGNTWITTER_H
#define LEETCODEINCPP_DESIGNTWITTER_H

#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

using pii = pair<int, int>;

bool cmp(const pii &p1, const pii &p2) {
    return p1.second > p2.second;
}

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : m_time(0) {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ++m_time; // 更新时间
        m_user_tweets[userId].push_back(make_pair(tweetId, m_time));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pii> tweets;
        vector<int> ans;
        auto myTweets = m_user_tweets[userId];
        // 自己的推文
        for (auto elem : myTweets) {
            tweets.push_back(elem);
        }
        // 关注者的推文
        for (auto elem : m_user_followees[userId]) {
            for (auto tweet : m_user_tweets[elem]) {
                tweets.push_back(tweet);
            }
        }
        // 排序 tweets
        sort(tweets.begin(), tweets.end(), cmp);
        int count = 0;
        for (auto elem : tweets) {
            ans.push_back(elem.first);
            ++count;
            if (count >= 10) break;
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        auto it = m_user_followees.find(followerId);
        if (it == m_user_followees.end()) {
            list<int> followees;
            followees.push_back(followeeId);
            m_user_followees.insert(make_pair(followerId, followees));
        } else {
            auto followees = it->second;
            if (find(followees.begin(), followees.end(), followeeId) != followees.end()) {
                return;
            } else {
                it->second.push_back(followeeId);
            };
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        auto it = m_user_followees.find(followerId);
        if (it != m_user_followees.end()) {
            it->second.remove(followeeId);
        }
    }



private:
    unordered_map<int, vector<pii>> m_user_tweets; // 用户--推文/发文时间
    unordered_map<int, list<int>> m_user_followees; // 用户--关注者
    int m_time; // 时间
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
    vector<int> ans;
    for (int i = 0; i < cmd.size(); ++i) {
        if (cmd[i] == "postTweet") {
            twitter->postTweet(data[i][0], data[i][1]);
            cout << "null" << ",";
        } else if (cmd[i] == "follow") {
            twitter->follow(data[i][0], data[i][1]);
            cout << "null" << ",";
        } else if (cmd[i] == "getNewsFeed") {
            ans = twitter->getNewsFeed(data[i][0]);
            cout << "[";
            for (auto elem : ans) {
                cout << elem << ",";
            }
            cout << "],";
        }
    }
}

#endif //LEETCODEINCPP_DESIGNTWITTER_H
