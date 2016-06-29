//
//  JumpGameII.h
//  LeetCode
//
//  Created by Jerome on 6/28/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef JumpGameII_h
#define JumpGameII_h

#include "DataStructure.h"

using namespace std;

/*
 
 45. Jump Game II
 
 */

int jumpII(vector<int>& nums) {
    if (nums.size()==1) return 0;
    int result = 0;
    int n = nums.size()-1;
    queue<int> myqueue;
    myqueue.push(0);
    vector<bool> visited(nums.size(), false);
    visited[0] = true;
    while(!myqueue.empty()) {
        int qs = myqueue.size();
        for (int i = 0; i < qs; i++) {
            int idx = myqueue.front();
            myqueue.pop();
            if (idx==n) return result;
            int steps = nums[idx];
            for (int s = steps; s >= 1; s--) {
                if (s+idx==n) return result+1;
                if (s+idx<=n && !visited[s+idx]) {
                    visited[s+idx] = true;
                    myqueue.push(s+idx);
                }
            }
        }
        result++;
    }
    
    return result;
}

#endif /* JumpGameII_h */
