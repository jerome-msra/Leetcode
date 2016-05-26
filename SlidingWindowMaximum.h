//
//  SlidingWindowMaximum.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SlidingWindowMaximum_h
#define SlidingWindowMaximum_h

#include "DataStructure.h"

using namespace std;

/************************** 239. Sliding Window Maximum *************************/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i=0; i<nums.size(); i++) {
        if (!dq.empty() && dq.front() == i-k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

#endif /* SlidingWindowMaximum_h */
