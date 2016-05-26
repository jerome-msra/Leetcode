//
//  MaximumGap.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MaximumGap_h
#define MaximumGap_h

#include "DataStructure.h"

using namespace std;

/************************** 164. Maximum Gap *************************/

int maximumGap(vector<int>& nums) {
    if (nums.size()<2) return 0;
    int mmax = INT_MIN, mmin = INT_MAX;
    vector<int> bucketMin;
    vector<int> bucketMax;
    vector<int> bucketCount;
    int n = nums.size();
    for (auto i : nums) {
        mmax = (mmax < i) ? i : mmax;
        mmin = (mmin > i) ? i : mmin;
    }
    int maxgap = max(1, (mmax - mmin) / (n-1)); // maxgap is also the size of each bucket
    int bucketNum = (mmax - mmin) / maxgap + 1;
    bucketMin.resize(bucketNum, INT_MAX);
    bucketMax.resize(bucketNum, INT_MIN);
    bucketCount.resize(bucketNum, 0);
    for (int i  = 0; i < nums.size(); i++) {
        int bucketId = (nums[i] - mmin) / maxgap;
        bucketCount[bucketId]++;
        bucketMin[bucketId] = (bucketMin[bucketId] > nums[i]) ? nums[i] : bucketMin[bucketId];
        bucketMax[bucketId] = (bucketMax[bucketId] < nums[i]) ? nums[i] : bucketMax[bucketId];
    }
    int lastMax = mmin;
    int result = INT_MIN;
    for (int i = 0; i < bucketNum; i++) {
        if (bucketCount[i]>0) {
            result = (result < bucketMin[i]-lastMax) ? bucketMin[i]-lastMax : result;
            lastMax = bucketMax[i];
        }
    }
    
    return result;
}

#endif /* MaximumGap_h */
