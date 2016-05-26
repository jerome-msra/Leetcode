//
//  PopulatingNextRightPointerII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PopulatingNextRightPointerII_h
#define PopulatingNextRightPointerII_h

#include "DataStructure.h"

using namespace std;

/************** 117. Populating Next Right Pointers in Each Node II *******************/

int trap(vector<int>& height) {
    if(height.size()<3) return 0;
    stack<int> s;
    s.push(0);
    int water = 0;
    
    for(int i=1; i<height.size(); i++) {
        if(height[i]>height[s.top()]) {
            int bottom = height[s.top()];
            s.pop();
            while(!s.empty() && height[i]>=height[s.top()]) {
                water += (height[s.top()]-bottom)*(i-s.top()-1);
                bottom = height[s.top()];
                s.pop();
            }
            if(!s.empty()) water += (height[i]-bottom)*(i-s.top()-1);
        }
        s.push(i);
    }
    
    return water;
}

#endif /* PopulatingNextRightPointerII_h */
