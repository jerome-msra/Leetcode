//
//  RemoveInvalidParenthesisDFS.h
//  LeetCode
//
//  Created by Jerome on 6/5/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RemoveInvalidParenthesisDFS_h
#define RemoveInvalidParenthesisDFS_h

#include "DataStructure.h"

using namespace std;

/**
 DFS seems very difficult. Key point is :
• How to guarantee that the minimum number of parenthesis is removed.
• How to avoid duplicates without using a set

For the first question, a counter is used. Scan the string, increase the counter for '(' and decrease for ')'. Only when the counter is negative, we conduct the removal. That means we can remove minimum number of ')' when ')' is more than '('.

For the second, use two variables to record the position where either parenthesis was removed last time. Each time, start from this position and jump the duplicated characters.

What if '(' is more than ')'? A clever idea is that, scan the string from right to left and treat '(' as ')' and verse vase.

**/

void removeHelper(vector<string> & result, string s, int prev_i, int prev_j, vector<char> par) {
    int leftpar = 0;
    for (int i = prev_i; i < s.length(); i++) {
        if (s[i]==par[0]) leftpar++;
        if (s[i]==par[1]) leftpar--;
        if (leftpar<0) {
            for (int j = prev_j; j <= i; j++) {
                if (s[j]==par[1] && (j==prev_j || s[j]!=s[j-1])) {
                    removeHelper(result, s.substr(0,j)+s.substr(j+1), i, j, par);
                }
            }
            return;
        }
    }
    
    string revs = s;
    reverse(revs.begin(), revs.end());
    if (par[0]=='(')
        removeHelper(result, revs, 0, 0, vector<char>{')','('});
    else
        result.push_back(revs);
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    removeHelper(result, s, 0, 0, vector<char>{'(',')'});
    return result;
}

#endif /* RemoveInvalidParenthesisDFS_h */
