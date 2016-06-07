//
//  SelfCrossing.h
//  LeetCode
//
//  Created by Jerome on 6/7/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SelfCrossing_h
#define SelfCrossing_h

#include "DataStructure.h"

using namespace std;

/* There will be three kinds of crossing
 */

bool isSelfCrossing(vector<int>& x) {
    for (int i = 0; i < x.size(); i++) {
        
        /* The 1st case: cross with the last 3rd move
         
             (i-2)
         <---------
         |        |
  (i-1)  |        | (i-3)
         |        |
         |--------|---->
             (i)  |
                  O(start point)
         
         */
        if (i>=3 && x[i]>=x[i-2] && x[i-1]<=x[i-3]) return true;
        
        /* The 2nd case : meet with the last 4th move
         
              (i-3)
         <------------
         |           |
         |           | (i-4)
         |           |
         |           |
   (i-2) |           O (start point)
         |           |
         |           | (i)
         |           |
         |----------->
              (i-1)
         */
        if (i>=4 && x[i-1]==x[i-3] && x[i-2]<=x[i]+x[i-4]) return true;
        
        /* The 3rd case : cross with the last 5 move
         
         <----------
         |         |
         |         |
         |     <---|---------
         |         |        |
         |         |        |
         |         O        |
         |                  |
         |------------------>
         */
        
        if (i>=5 && x[i-2]>=x[i-4] && x[i-1]<=x[i-3] && x[i-4]+x[i]>=x[i-2] && x[i-1]+x[i-5]>=x[i-3]) return true;
    }
    return false;
}

#endif /* SelfCrossing_h */
