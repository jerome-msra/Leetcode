//
//  NestedListWeightedSumII.h
//  LeetCode
//
//  Created by Jerome on 7/3/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef NestedListWeightedSumII_h
#define NestedListWeightedSumII_h

#include "DataStructure.h"

using namespace std;

void dfsHelper(NestedInteger & ni, int depth, vector<int> & result);

int depthSumInverse(vector<NestedInteger>& nestedList) {
    vector<int> result;
    for (auto it : nestedList) {
        dfsHelper(it, 0, result);
    }
    int sum = 0;
    int n = result.size();
    for (int i = 0; i < n; i++) {
        sum += result[i] * (n-i);
    }
    return sum;
}


void dfsHelper(NestedInteger & ni, int depth, vector<int> & result) {
    if (depth>=result.size()) result.push_back(0);
    if (ni.isInteger()) {
        result[depth] += ni.getInteger();
        return;
    }
    for (auto next : ni.getList()) {
        dfsHelper(next, depth+1, result);
    }
}

#endif /* NestedListWeightedSumII_h */
