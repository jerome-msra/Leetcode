//
//  CombinationSum.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CombinationSum_h
#define CombinationSum_h

#include "DataStructure.h"

using namespace std;

/****************************************** 39 COMBINATION SUM ******************************************/

int m_target;
vector<int> original;

void combinationSumHelper(vector<vector<int>> & result, vector<int> & nums, int n, int sum) {
    if (sum == m_target) result.push_back(nums);
    else if (sum > m_target) return;
    for (int i = n; i < original.size(); i++) {
        nums.push_back(original[i]);
        combinationSumHelper(result, nums, i, sum+original[i]);
        nums.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.size() == 0) return result;
    original = candidates;
    m_target = target;
    vector<int> nums;
    combinationSumHelper(result, nums, 0, 0);
    
    return result;
}

#endif /* CombinationSum_h */
