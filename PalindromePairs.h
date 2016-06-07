//
//  PalindromePairs.h
//  LeetCode
//
//  Created by Jerome on 6/6/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PalindromePairs_h
#define PalindromePairs_h

#include "DataStructure.h"

using namespace std;

bool isPalin(string s) {
    int i = 0, j = s.length()-1;
    while(i<j) {
        if (s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> strMap;
    vector<vector<int>> result;
    for (int i = 0; i < words.size(); i++) {
        string revStr = words[i];
        reverse(revStr.begin(), revStr.end());
        strMap[revStr] = i;
    }
    
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int j = 0; j < word.size(); j++) {
            string pre = word.substr(0,j);
            string post = word.substr(j);
            if (strMap.find(pre)!=strMap.end() && isPalin(post)) {
                if (i!=strMap[pre]) result.push_back({i, strMap[pre]});
                if (pre.length()==0) result.push_back({strMap[pre], i});
            }
            if (strMap.find(post)!=strMap.end() && isPalin(pre)) {
                if (i!=strMap[post]) result.push_back({strMap[post], i});
            }
        }
    }
    
    return result;
}

#endif /* PalindromePairs_h */
