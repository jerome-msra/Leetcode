//
//  InsertInterval.h
//  LeetCode
//
//  Created by Jerome on 6/30/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef InsertInterval_h
#define InsertInterval_h

#include "DataStructure.h"

using namespace std;

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    int i = 0;
    vector<Interval> result;
    while (i<intervals.size() && intervals[i].end < newInterval.start) {
        result.push_back(intervals[i]);
        i++;
    }
    int ns = newInterval.start, ne = newInterval.end;
    while(i<intervals.size() && intervals[i].start <= newInterval.end) {
        ns = min(intervals[i].start, ns);
        ne = max(intervals[i].end, ne);
        i++;
    }
    result.push_back(Interval(ns, ne));
    while(i<intervals.size()) result.push_back(intervals[i++]);
    
    return result;
}

#endif /* InsertInterval_h */
