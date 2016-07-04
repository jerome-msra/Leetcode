//
//  LineReflection.h
//  LeetCode
//
//  Created by Jerome on 7/4/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LineReflection_h
#define LineReflection_h

#include "DataStructure.h"

using namespace std;

bool isReflected(vector<pair<int, int>>& points) {
    unordered_map<int, unordered_set<int>> ptsMap;
    for (auto p : points) {
        ptsMap[p.second].insert(p.first);
    }
    double prevAxis = 0;
    int num = 0;
    for (auto pm : ptsMap) {
        int minx = INT_MAX, maxx = INT_MIN;
        for (auto p : pm.second) {
            minx = min(minx, p);
            maxx = max(maxx, p);
        }
        
        double axis = (minx+maxx)/2.0;
        if (num==0) { prevAxis = axis; num++; }
        else if (axis != prevAxis) return false;
        
        for (auto p : pm.second) {
            int x = p;
            if (x==axis) continue;
            int ax = axis * 2.0 - x;
            // std::cout << axis << " " << x << " " << ax << std::endl;
            if (pm.second.count(ax)>0) continue;
            else return false;
        }
    }
    
    return true;
}

#endif /* LineReflection_h */
