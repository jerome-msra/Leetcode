//
//  ShortestPalindrome.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ShortestPalindrome_h
#define ShortestPalindrome_h

#include "DataStructure.h"

using namespace std;

string shortestPalindrome(string s) {
    int l = s.length();
    vector<vector<bool>> dpresult(l, vector<bool>(l, false));
    for (int i = 0; i < l; i++) dpresult[i][i] = true;
    for (int i = 1; i <= l/2; i++) {
        for (int j = 1; j <= min(i,l-i)+1; j++) {
            if (i-j>=0 && i+j<l)
                dpresult[i-j][i+j] = dpresult[i-j+1][i+j-1] && s[i-j]==s[i+j];
            dpresult[i-j+1][i+j] = (j==1 || dpresult[i-j+2][i+j-1]) && s[i-j+1]==s[i+j];
        }
    }
    int i;
    for (i = l-1; i >=0; i--) {
        if(dpresult[0][i]) break;
    }
    string result = "";
    string rem = s.substr(i+1);
    reverse(rem.begin(), rem.end());
    result = rem + s;
    return result;
}

#endif /* ShortestPalindrome_h */
