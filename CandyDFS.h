//
//  CandyDFS.h
//  LeetCode
//
//  Created by Jerome on 6/28/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CandyDFS_h
#define CandyDFS_h

#include "DataStructure.h"

using namespace std;

int dfsCandyGraph(vector<unordered_set<int>> & graph, vector<int> & candies, int node, vector<bool> & visited)

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 0);
    if (n==0 || n==1) return n;
    vector<unordered_set<int>> graph(n);
    int maxId = 0, maxRat = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (ratings[i]>maxRat) {
            maxRat = ratings[i];
            maxId = i;
        }
        if (i>0 && i<n-1) {
            if (ratings[i]>ratings[i-1]) graph[i].insert(i-1);
            if (ratings[i]>ratings[i+1]) graph[i].insert(i+1);
        }
        if (i==0) {
            if (ratings[i]>ratings[i+1]) graph[i].insert(i+1);
        }
        if (i==n-1) {
            if (ratings[i]>ratings[i-1]) graph[i].insert(i-1);
        }
    }
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfsCandyGraph(graph, candies, i, visited);
    }
    
    int result = 0;
    for (auto x : candies) result+=x;
    return result;
}

int dfsCandyGraph(vector<unordered_set<int>> & graph, vector<int> & candies, int node, vector<bool> & visited) {
    if (graph[node].empty()) {
        visited[node] = true;
        candies[node] = 1;
        return 1;
    }
    int maxCandies = INT_MIN;
    for (auto next : graph[node]) {
        if (!visited[next]) {
            int nextCandies = dfsCandyGraph(graph, candies, next, visited);
            maxCandies = max(maxCandies, nextCandies);
        }
        else {
            maxCandies = max(maxCandies, candies[next]);
        }
    }
    candies[node] = maxCandies + 1;
    visited[node] = true;
    return maxCandies + 1;
}

#endif /* CandyDFS_h */
