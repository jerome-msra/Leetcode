//
//  InterleavingString.h
//  LeetCode
//
//  Created by Jerome on 6/29/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef InterleavingString_h
#define InterleavingString_h

#include "DataStructure.h"

using namespace std;

/*
 
 97. Interleaving String
 
 */

bool isInterleave(string s1, string s2, string s3) {
    if (s3.length() != s1.length() + s2.length()) return false;
    vector<vector<bool>> dpresult(s1.length()+1, vector<bool>(s2.length()+1, false));
    dpresult[0][0] = true;
    int l1 = static_cast<int>(s1.length());
    int l2 = static_cast<int>(s2.length());
    for (int j = 1; j <= l2; j++) {
        dpresult[0][j] = s2.substr(0,j)==s3.substr(0,j);
    }
    for (int i = 1; i <= l1; i++) {
        dpresult[i][0] = s1.substr(0,i)==s3.substr(0,i);
    }
    
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            dpresult[i][j] = (dpresult[i][j-1] && s2[j-1]==s3[i+j-1]) || (dpresult[i-1][j]&& s1[i-1]==s3[i+j-1]);
            
        }
    }
    
    return dpresult[s1.length()][s2.length()];
}

#endif /* InterleavingString_h */
