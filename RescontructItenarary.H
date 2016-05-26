//
//  RescontructItenarary.H
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RescontructItenarary_h
#define RescontructItenarary_h

#include "DataStructure.h"

using namespace std;

/*********************************** 332. RECONSTRUCT ITENARARY **************************************/

unordered_map<string, multiset<string>> graph;

bool findpath(vector<string> & result, string place, int totalnumber) {
    if (result.size() == totalnumber) return true;
    if (graph.find(place) == graph.end() || graph[place].size() == 0) return false;
    multiset<string> neighbors = graph[place];
    for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
        string next = *it;
        result.push_back(next);
        size_t nextnum = graph[place].count(next);
        graph[place].erase(next);
        for (size_t i = 0; i < nextnum-1; i++) graph[place].insert(next);
        bool found = findpath(result, next, totalnumber);
        if (found) return true;
        else {
            result.pop_back();
            graph[place].insert(next);
        }
    }
    
    return false;
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto it : tickets) {
        graph[it.first].insert(it.second);
    }
    
    vector<string> result;
    if (tickets.size() == 0) return result;
    result.push_back("JFK");
    findpath(result, "JFK", tickets.size()+1);
    
    return result;
}

#endif /* RescontructItenarary_h */
