//
//  CourseScheduleII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CourseScheduleII_h
#define CourseScheduleII_h

#include "DataStructure.h"

using namespace std;

/****************************************** 210. Course Schedule II ******************************************/

int currentLabel;

void dfsFindOrder(vector<int> & result, vector<vector<int>> & graph, unordered_set<int> & visited, int start, int & numCourses) {
    visited.insert(start);
    for (auto it : graph[start]) {
        if (visited.count(it) == 0) {
            dfsFindOrder(result, graph, visited, it, numCourses);
        }
    }
    result[start] = currentLabel;
    currentLabel--;
    //visited.erase(start);
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph;
    vector<int> indegree(numCourses, 0);
    vector<int> result(numCourses, 0);
    unordered_set<int> visited;
    graph.resize(numCourses);
    currentLabel = numCourses-1;
    for (auto pre : prerequisites) {
        graph[pre.second].push_back(pre.first);
        indegree[pre.first]++;
    }
    
    vector<int> _indegree = indegree;
    
    queue<int> myqueue;
    for (int i = 0; i < _indegree.size(); i++) {
        if (_indegree[i] == 0) myqueue.push(i);
    }
    
    while(!myqueue.empty()) {
        int node = myqueue.front();
        myqueue.pop();
        for (auto it : graph[node]) {
            _indegree[it]--;
            if (_indegree[it] == 0) myqueue.push(it);
        }
    }
    
    for (size_t i = 0; i < numCourses; i++) {
        if (_indegree[i] > 0) return vector<int>{};
    }
    
    for (int i = 0; i < numCourses; i++) {
        if (visited.count(i) == 0) {
            dfsFindOrder(result, graph, visited, i, numCourses);
        }
    }
    
    vector<int> order(numCourses, 0);
    for (int i = 0; i < result.size(); i++) {
        order[result[i]] = i;
    }
    
    return order;
}

#endif /* CourseScheduleII_h */
