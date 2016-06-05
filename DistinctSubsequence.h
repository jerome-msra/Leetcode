//
//  DistinctSubsequence.h
//  LeetCode
//
//  Created by Jerome on 6/5/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef DistinctSubsequence_h
#define DistinctSubsequence_h

#include "DataStructure.h"

using namespace std;

/**
 The Dynamic programming principle is as the follows:
 dp[i][j] means the number of distinct subsequences of t[0..i] in s[0..j]. 
 So if current characters (we say it's t[i] and s[j] are the same, then we can
 
 s : |------------|c
 t : |-------|c
 
 (1) delete the character in s ---- in this case, add dp[i][j-1]
 (2) not delete the character in s ---- in this case, add dp[i-1][j-1]
 to get current value. so dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
 
 If the current characters are different, then we must 
 
 s : |-----------|c
 t : |-------|b
 
 we must delete the character in s to get the string t, so dp[i][j] = dp[i][j-1]
 
**/

int numDistinct(string s, string t) {
    int ns = s.length()+1, nt = t.length()+1;
    vector<vector<int>> dpresult(nt, vector<int>(ns, 0));
    for (int i = 0; i < ns; i++) {
        dpresult[0][i] = 1;
    }
    for (int i = 1; i < nt; i++) {
        for (int j = 1; j < ns; j++) {
            if (t[i-1]!=s[j-1]) dpresult[i][j] = dpresult[i][j-1];
            else dpresult[i][j] = dpresult[i-1][j-1] + dpresult[i][j-1];
        }
    }
    
    return dpresult[nt-1][ns-1];
}

#endif /* DistinctSubsequence_h */
