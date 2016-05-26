//
//  SubstringWithConcatenationOfWords.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SubstringWithConcatenationOfWords_h
#define SubstringWithConcatenationOfWords_h


#include "DataStructure.h"

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string,int> myset;
    int wl = words[0].length();
    for (auto w : words) myset[w]++;
    vector<int> result;
    int total = words.size();
    int start = 0, end = 0;
    if (s.length()<words.size()) return result;
    while (end < s.length()) {
        unordered_map<string,int> temp = myset;
        start = end;
        int temptotal = total;
        while(end<s.length() && total>0) {
            string sub = s.substr(end, wl);
            if (myset.find(sub)!=myset.end() && myset[sub]>0) {
                myset[sub]--;
                total--;
                end += wl;
            }
            else break;
        }
        if (!total) {
            result.push_back(start);
        }
        total = temptotal;
        myset = temp;
        end=start+wl;
    }
    return result;
}

#endif /* SubstringWithConcatenationOfWords_h */
