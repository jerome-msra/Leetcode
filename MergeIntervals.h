//
//  MergeIntervals.h
//  LeetCode
//
//  Created by Jerome on 6/8/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MergeIntervals_h
#define MergeIntervals_h

#include "DataStructure.h"

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool compareInterval(Interval & a, Interval & b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compareInterval);
    vector<Interval> result;
    int i = 0;
    while(i < intervals.size()) {
        int start = intervals[i].start;
        int end = intervals[i].end;
        i++;
        while(i<intervals.size() && intervals[i].start <= end) { end = max(end, intervals[i].end); i++; }
        result.push_back(Interval(start, end));
    }
    return result;
}

#endif /* MergeIntervals_h */
