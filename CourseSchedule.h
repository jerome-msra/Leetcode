//
//  CourseSchedule.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CourseSchedule_h
#define CourseSchedule_h

#include "DataStructure.h"

using namespace std;

/*********************************** 207 COURSES SCHEDULE **************************************/

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses, unordered_set<int>{});
    vector<int> indegree(numCourses, 0);
    for (size_t i = 0; i < prerequisites.size(); i++) {
        graph[prerequisites[i].second].insert(prerequisites[i].first);
        indegree[prerequisites[i].first]++;
    }
    queue<int> myqueue;
    for (size_t i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) myqueue.push(i);
    }
    
    while(!myqueue.empty()) {
        int node = myqueue.front();
        myqueue.pop();
        for (auto it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) myqueue.push(it);
        }
    }
    
    for (size_t i = 0; i < numCourses; i++) {
        if (indegree[i] > 0) return false;
    }
    
    return true;
}

#endif /* CourseSchedule_h */
