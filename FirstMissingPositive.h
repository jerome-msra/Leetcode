//
//  FirstMissingPositive.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef FirstMissingPositive_h
#define FirstMissingPositive_h

#include "DataStructure.h"

using namespace std;

/************************** 41. First Missing Positive *************************/


int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++)
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < n; i++)
        if (nums[i] != i + 1)
            return i + 1;
    return n + 1;
}

#endif /* FirstMissingPositive_h */
