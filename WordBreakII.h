//
//  WordBreakII.h
//  LeetCode
//
//  Created by Jerome on 6/27/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordBreakII_h
#define WordBreakII_h

#include "DataStructure.h"

using namespace std;

void wordBreakHelper(vector<string> & result, string & current, string & s, unordered_set<string> & wordDict, vector<bool> & possible, int pos);

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> result;
    string current;
    vector<bool> possible(s.length()+1, true);
    wordBreakHelper(result, current, s, wordDict, possible, 0);
    return result;
}

void wordBreakHelper(vector<string> & result, string & current, string & s, unordered_set<string> & wordDict, vector<bool> & possible, int pos) {
    if (pos==s.length()) {
        result.push_back(current);
        return;
    }
    
    for (int i = pos+1; i <= s.length(); i++) {
        string curr = s.substr(pos, i-pos);
        if (wordDict.count(curr)>0 && possible[i]) {
            string prevCurrent = current;
            if (current.length()==0) current += curr;
            else current += " " + curr;
            int prevSize = static_cast<int>(result.size());
            wordBreakHelper(result, current, s, wordDict, possible, i);
            if (prevSize == result.size()) {
                possible[i] = false;
            }
            current = prevCurrent;
        }
    }
    
    return;
}

#endif /* WordBreakII_h */
