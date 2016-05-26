//
//  LongestSubstringWithKDistinct.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestSubstringWithKDistinct_h
#define LongestSubstringWithKDistinct_h

#include "DataStructure.h"

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    vector<unordered_set<char>> myset(s.length());
    unordered_set<char> temp;
    for (int i = 0; i < s.length(); i++) {
        temp.insert(s[i]);
        myset[i] = temp;
    }
    int n = s.length();
    if (myset[n-1].size()<=k) return n;
    int start = 0, end = n-1;
    while(start<end) {
        unordered_set<char> * endset = &(myset[end]);
        unordered_set<char> * startset = &(myset[start]);
        myset[end].erase(myset[start].begin(), myset[start].end());
        if (endset->size()<=k) return end-start;
        else {
            endset->insert(myset[start].begin(),myset[start].end());
            endset->erase(myset[start+1].begin(), myset[start+1].end());
            if (endset->size()<=k) return end-start-1;
            endset->insert(myset[start+1].begin(), myset[start+1].end());
            endset = &(myset[end-1]);
            endset->erase(startset->begin(), startset->end());
            if (endset->size()<=k) return end-start-1;
            end--;
            start++;
        }
    }
    
    return 0;
}

#endif /* LongestSubstringWithKDistinct_h */
