//
//  TheSkylineProblem.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef TheSkylineProblem_h
#define TheSkylineProblem_h

#include "DataStructure.h"

using namespace std;

/************************** 218. The Skyline Problem *************************/

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    multimap<int, int> coords;
    for (const vector<int> & building : buildings) {
        coords.emplace(building[0], building[2]);
        coords.emplace(building[1], -building[2]);
    }
    
    multiset<int> heights = { 0 };
    vector<pair<int, int>> corners;
    int x = -1; // previous one - x coordinate
    int y = 0; // previous one - y coordinate
    for (const pair<int, int> & p : coords) {
        if ((x >= 0) && (p.first != x) && (corners.empty() || (corners.rbegin()->second != y))) {
            corners.emplace_back(x, y);
        }
        
        if (p.second >= 0) {
            heights.insert(p.second);
        }
        else {
            heights.erase(heights.find(-p.second));
        }
        
        x = p.first;
        y = *heights.rbegin();
    }
    
    if (!corners.empty()) {
        corners.emplace_back(x, 0);
    }
    
    return corners;
}

// for better understand

static bool pairEqual(pair<int,int> p1, pair<int,int> p2) {
    return p1.second == p2.second;
}

vector<pair<int, int>> getSkylineII(vector<vector<int>>& buildings) {
    multimap<int,int> buildMap;
    for (auto b : buildings) {
        buildMap.emplace(b[0], b[2]);
        buildMap.emplace(b[1], -b[2]);
    }
    
    multiset<int> heights{0};
    map<int,int> corners;
    for (auto b : buildMap) {
        if (b.second > 0) {
            heights.insert(b.second);
        }
        else {
            heights.erase(heights.find(-b.second));
        }
        // find the highest point at this position
        corners[b.first] = *heights.rbegin();
    }
    
    // remove duplicates
    vector<pair<int, int>> results;
    unique_copy(corners.begin(), corners.end(), back_insert_iterator<vector<pair<int, int>>>(results), pairEqual);
    return results;
}



#endif /* TheSkylineProblem_h */
