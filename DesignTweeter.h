//
//  DesignTweeter.h
//  LeetCode
//
//  Created by Jerome on 7/3/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef DesignTweeter_h
#define DesignTweeter_h

#include "DataStructure.h"

using namespace std;

struct Tweet {
    Tweet(int tid, int ttime) : id(tid), timestamp(ttime) {};
    int id, timestamp;
};

class myCompare {
public:
    bool operator()(Tweet & t1, Tweet & t2) const {
        return t1.timestamp < t2.timestamp;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        t = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet newtweet(tweetId, t++);
        tweetMap[userId].push_back(newtweet);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, myCompare> myqueue;
        for (auto follower : followerMap[userId]) {
            vector<Tweet> & ft = tweetMap[follower];
            int num = 10;
            for (int i = ft.size()-1; i >= 0 && num>0; i--,num--) {
                myqueue.push(ft[i]);
            }
        }
        vector<Tweet> & ownt = tweetMap[userId];
        int num = 10;
        for (int i = ownt.size()-1; i>=0 && num>0; i--, num--) {
            myqueue.push(ownt[i]);
        }
        vector<int> result;
        while(!myqueue.empty() && result.size()<10) {
            result.push_back(myqueue.top().id);
            myqueue.pop();
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId!=followeeId)
            followerMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
    
    int t;
    unordered_map<int, vector<Tweet>> tweetMap;
    unordered_map<int, unordered_set<int>> followerMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

#endif /* DesignTweeter_h */
