//
//  LargestRectangleInHistogram.h
//  LeetCode
//
//  Created by Jerome on 6/28/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LargestRectangleInHistogram_h
#define LargestRectangleInHistogram_h

#include "DataStructure.h"

using namespace std;

/*
 
 84. Largest Rectangle in Histogram
 
 */

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int n = heights.size();
    stack<int> myIdxStack;
    int left=0, right=0, height = 0;
    int result = 0;
    while(right < n) {
        if (myIdxStack.empty() || heights[right]>heights[myIdxStack.top()]) myIdxStack.push(right++);
        else {
            height = heights[myIdxStack.top()];
            myIdxStack.pop();
            left = (myIdxStack.empty()) ? -1 : myIdxStack.top();
            result = max(result, height * (right-left-1));
        }
    }
    
    return result;
}

#endif /* LargestRectangleInHistogram_h */
