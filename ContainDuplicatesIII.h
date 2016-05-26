//
//  ContainDuplicatesIII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ContainDuplicatesIII_h
#define ContainDuplicatesIII_h

#include "DataStructure.h"

using namespace std;

/**************************** 220. Contains Duplicate III ******************************/

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.size() <= 1 || k == 0) return false;
    set<long> slidingwindow;
    int l = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i-l > k) {
            slidingwindow.erase(nums[l++]);
        }
        auto it = slidingwindow.lower_bound((long)nums[i] - (long)t);
        if (it!=slidingwindow.end() && *it <= ((long)nums[i] + (long)t)) {
            return true;
        }
        slidingwindow.insert(nums[i]);
    }
    return false;
}

#endif /* ContainDuplicatesIII_h */
