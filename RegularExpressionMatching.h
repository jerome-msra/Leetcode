//
//  RegularExpressionMatching.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RegularExpressionMatching_h
#define RegularExpressionMatching_h

#include "DataStructure.h"

using namespace std;

bool isMatch(string s, string p) {
    int sl = s.length(), pl = p.length();
    vector<vector<bool>> dpresult(sl+1, vector<bool>(pl+1, false));
    dpresult[0][0] = true;
    for (int i = 0; i <= sl; i++) {
        for (int j = 1; j <= pl; j++) {
            if (p[j-1]!='.' && p[j-1]!='*') {
                if (i>0) dpresult[i][j] = dpresult[i-1][j-1] && s[i-1]==p[j-1];
            }
            else if (p[j-1]=='.') {
                if (i>0) dpresult[i][j] = dpresult[i-1][j-1];
            }
            else {
                bool noneMatch = dpresult[i][j-2];
                bool oneMatch = dpresult[i][j-1];
                bool multiMatch = i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dpresult[i-1][j];
                dpresult[i][j] = noneMatch || oneMatch || multiMatch;
            }
        }
    }
    return dpresult[sl][pl];
}

#endif /* RegularExpressionMatching_h */
