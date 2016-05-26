//
//  PermutationII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PermutationII_h
#define PermutationII_h

#include "DataStructure.h"

using namespace std;

/*********************************** 47 PERMUTATIONS II **************************************/

void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}

void permuteUniqueHelper(vector<vector<int>> & result, vector<int> & nums, int n) {
    if (n == nums.size() - 1) {
        result.push_back(nums);
        //return;
    }
    for (int i = n; i < nums.size(); i++) {
        if (i != n && nums[i] == nums[n]) continue;
        swap(nums[i], nums[n]);
        permuteUniqueHelper(result, nums, n + 1);
        // swap(nums[i], nums[n]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() == 0) return result;
    sort(nums.begin(), nums.end());
    permuteUniqueHelper(result, nums, 0);
    
    return result;
}

#endif /* PermutationII_h */
