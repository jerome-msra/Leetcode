//
//  SubsetII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SubsetII_h
#define SubsetII_h

#include "DataStructure.h"

using namespace std;

/****************************************** 90 SUBSET II ******************************************/

vector<int> original;

void subsetsDupHelper(vector<vector<int>> & result, vector<int> & sub, int n) {
    result.push_back(sub);
    int i = n;
    while (i < original.size()) {
        int tmp = original[i];
        sub.push_back(original[i]);
        subsetsDupHelper(result, sub, i+1);
        sub.pop_back();
        while(i < original.size() && original[i] == tmp) {
            i++;
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() == 0) return result;
    sort(nums.begin(), nums.end());
    
    original = nums;
    vector<int> sub;
    subsetsDupHelper(result, sub, 0);
    return result;
}

#endif /* SubsetII_h */
