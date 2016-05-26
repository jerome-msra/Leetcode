//
//  CountOfRangeSum.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CountOfRangeSum_h
#define CountOfRangeSum_h

#include "DataStructure.h"

using namespace std;

/************************** 327. Count of Range Sum *************************/

vector<long> rangeSum;

long getSum(int i, int j) {
    return rangeSum[j]-rangeSum[i];
}

int searchRange(int left, int right, int lower, int upper) {
    if (left == right) return (rangeSum[left]>=lower&&rangeSum[left]<=upper);
    int mid = (left+right)/2;
    int count = searchRange(left, mid, lower, upper) + searchRange(mid+1, right, lower, upper);
    int k = mid+1, j = mid+1;
    for (int i = left; i <= mid; i++) {
        while(j<=right && getSum(i,j)<lower) j++;
        while(k<=right && getSum(i,k)<=upper) k++;
        count += k-j;
    }
    inplace_merge(rangeSum.begin()+left, rangeSum.begin()+mid+1, rangeSum.begin()+right+1);
    return count;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    if (nums.size()==0) return 0;
    size_t n = nums.size();
    rangeSum.resize(n, 0);
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        rangeSum[i] = sum;
    }
    int result = searchRange(0, n-1, lower, upper);
    return result;
}

#endif /* CountOfRangeSum_h */
