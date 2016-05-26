//
//  CreatingMaxNumber.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CreatingMaxNumber_h
#define CreatingMaxNumber_h

#include "DataStructure.h"

using namespace std;

bool greaterr(vector<int> & nums1, int start1, vector<int> & nums2, int start2) {
    while(start1 < nums1.size() && start2 < nums2.size()) {
        if (nums1[start1] < nums2[start2]) return false;
        else if (nums1[start1] > nums2[start2]) return true;
        start1++; start2++;
    }
    return start1<nums1.size();
}

vector<int> maxSubarray(vector<int> & nums, int length) {
    vector<int> result(length, 0);
    int len = 0, n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        while(len && len+n-i>length && nums[i] > result[len-1]) {
            len--;
        }
        if (len<length) result[len++] = nums[i];
    }
    return result;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> result(k, 0);
    int n = nums1.size(), m = nums2.size();
    for (int i = max(0, k-m); i <= min(k,n); i++) {
        vector<int> res1 = maxSubarray(nums1, i);
        vector<int> res2 = maxSubarray(nums2, k-i);
        vector<int> tempRes(k, 0);
        int p1 = 0, p2 = 0, temp = 0;
        while(p1<res1.size() || p2<res2.size()) {
            tempRes[temp++] = greaterr(res1, p1, res2, p2) ? res1[p1++] : res2[p2++];
        }
        if (greaterr(tempRes, 0, result, 0)) result = tempRes;
    }
    return result;
}

#endif /* CreatingMaxNumber_h */
