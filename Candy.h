//
//  Candy.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef Candy_h
#define Candy_h

#include "DataStructure.h"

using namespace std;

/************************** 135. Candy *************************/


int candy(vector<int>& ratings) {
    vector<int> candy(ratings.size(), 0);
    size_t n = ratings.size();
    
    vector<unordered_set<int>> graph(n);
    vector<int> myqueue;
    for (int i = 0; i < ratings.size(); i++) {
        if (i>0 && i<n-1) {
            if (ratings[i]>ratings[i-1]&&ratings[i]>ratings[i+1]) {
                graph[i].insert(i-1);
                graph[i].insert(i+1);
            }
            else if (ratings[i]>ratings[i-1]) {
                graph[i].insert(i-1);
            }
            else if (ratings[i]>ratings[i+1]) {
                graph[i].insert(i+1);
            }
        }
        else if (i==0 && ratings[i]>ratings[i+1]) {
            graph[i].insert(i+1);
        }
        else if (i==n-1 && ratings[i]>ratings[i-1]) {
            graph[i].insert(i-1);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (graph[i].empty()) candy[i]=1;
        else myqueue.push_back(i);
    }
    
    while(!myqueue.empty()) {
        int m = myqueue.size();
        vector<int> current;
        for (auto iter = myqueue.begin(); iter!=myqueue.end(); ) {
            int node = *iter;
            unordered_set<int> myset = graph[node];
            int nmax = INT_MIN;
            bool flag = false;
            for (auto s:myset) {
                if (!graph[s].empty()) { flag = true; break; }
                if (graph[s].empty()) nmax = max(nmax, candy[s]);
            }
            if (!flag) {
                candy[node] = nmax+1;
                current.push_back(node);
                iter = myqueue.erase(iter);
            }
            else {
                iter++;
            }
        }
        for (auto c:current) {
            graph[c].clear();
        }
    }
    
    int sum = 0;
    for (auto c:candy) sum+=c;
    return sum;
}

#endif /* Candy_h */
