//
//  WildcardMatching.h
//  LeetCode
//
//  Created by Jerome on 6/27/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WildcardMatching_h
#define WildcardMatching_h

#include "DataStructure.h"

using namespace std;

bool isMatch(string s, string p) {
    vector<vector<bool>> dpresult(s.length()+1, vector<bool>(p.length()+1, false));
    dpresult[0][0] = true;
    bool start = p[0]=='*';
    for (int j = 0; j < p.length(); j++) {
        if (p[j]!='*') start = false;
        dpresult[0][j+1] = start;
    }
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < p.length(); j++) {
            if (p[j]=='?') dpresult[i+1][j+1] = dpresult[i][j];
            else if (p[j]=='*') dpresult[i+1][j+1] = dpresult[i][j] || dpresult[i][j+1] || dpresult[i+1][j];
            else dpresult[i+1][j+1] = dpresult[i][j] && s[i]==p[j];
        }
    }
    
    return dpresult[s.length()][p.length()];
}

#endif /* WildcardMatching_h */
