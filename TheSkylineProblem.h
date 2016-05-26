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
    int x = -1;
    int y = 0;
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

#endif /* TheSkylineProblem_h */
