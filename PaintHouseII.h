//
//  PaintHouseII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PaintHouseII_h
#define PaintHouseII_h

#include "DataStructure.h"

using namespace std;

int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n==0) return 0;
    int k = costs[0].size();
    
    int minValue = INT_MAX, minIdx = 0, secMinValue = INT_MAX;
    
    for (int i = 0; i < k; i++) {
        if (costs[0][i] < minValue) {
            minValue = costs[0][i];
            minIdx = i;
        }
        else {
            if (costs[0][i] < secMinValue) {
                secMinValue = costs[0][i];
            }
        }
    }
    
    for (size_t i = 1; i < n; i++) {
        int newMinValue = INT_MAX, newMinIdx = 0, newSecMinValue = INT_MAX;
        for (int j = 0; j < k; j++) {
            int sum = 0;
            if (j!=minIdx) sum = minValue + costs[i][j];
            else sum = secMinValue + costs[i][j];
            if (sum < newMinValue) {
                newMinValue = sum;
                newMinIdx = j;
            }
            else if (sum < newSecMinValue) {
                newSecMinValue = sum;
            }
        }
        minValue = newMinValue;
        minIdx = newMinIdx;
        secMinValue = newSecMinValue;
    }
    
    return minValue;
}

#endif /* PaintHouseII_h */
