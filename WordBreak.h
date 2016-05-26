//
//  WordBreak.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordBreak_h
#define WordBreak_h

#include "DataStructure.h"

using namespace std;

void wordBreakHelper(vector<string> & result, string & current, string & s, unordered_set<string> & wordDict, int level) {
    if (level == s.length()) {
        result.push_back(current);
        return;
    }
    for (int i = level+1; i <= s.length(); i++) {
        string sub = s.substr(level, i-level);
        if (wordDict.count(sub)>0) {
            string prevCurrent = current;
            if (current.length()>0) current += " "+sub;
            else current+=sub;
            wordBreakHelper(result, current, s, wordDict, i);
            current = prevCurrent;
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    string current;
    vector<string> result;
    wordBreakHelper(result, current, s, wordDict, 0);
    return result;
}

#endif /* WordBreak_h */
