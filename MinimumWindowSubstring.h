//
//  MinimumWindowSubstring.h
//  LeetCode
//
//  Created by Jerome on 6/27/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MinimumWindowSubstring_h
#define MinimumWindowSubstring_h

#include "DataStructure.h"

using namespace std;

string minWindow(string s, string t) {
    if (s.length()<t.length()) return "";
    unordered_map<char, int> smap;
    unordered_map<char, int> tset;
    for (auto tc : t) tset[tc]++;
    unordered_map<char, int> constTSet = tset;
    vector<int> dpresult(s.length(), -1);
    for (int i = 0; i < s.length(); i++) {
        if (constTSet.find(s[i])!=constTSet.end()) {
            smap[s[i]]++;
            if (tset.find(s[i])!=tset.end()) {
                tset[s[i]]--;
                if (tset[s[i]]==0) tset.erase(s[i]);
            }
        }
        if (tset.size()>0) {
            dpresult[i]=-1;
            continue;
        }
        else {
            int len = dpresult[i-1];
            if (len==-1) len = i;
            len++;
            int left = i-len+1;
            bool coverall = true;
            while(left<=i && coverall) {
                if (smap.find(s[left])!=smap.end()) {
                    if (smap[s[left]]==constTSet[s[left]]) {
                        coverall = false;
                        continue;
                    }
                    else {
                        smap[s[left]]--;
                    }
                }
                left++, len--;
            }
            dpresult[i] = len;
        }
    }
    
    int minLength = INT_MAX;
    int minIdx = 0;
    for (int i = 0; i < dpresult.size(); i++) {
        if (dpresult[i]!=-1) {
            if (dpresult[i]<minLength) {
                minLength = dpresult[i];
                minIdx = i;
            }
        }
    }
    
    if (minLength ==INT_MAX) return "";
    else return s.substr(minIdx-minLength+1, minLength);
}



string minWindowSubstr(string s, string t) {
    vector<int> tcharMap(256, 0);
    for (auto tc : t) tcharMap[tc]++;
    
    int minLen = INT_MAX, minIdx = 0;
    int start = 0, end = 0;
    int count = static_cast<int>(t.length());
    while(end < s.length()) {
        if (tcharMap[s[end]]>0) count--;
        tcharMap[s[end]]--;
        end++;
        while(count==0) {
            if (end - start < minLen) {
                minLen = end - start;
                minIdx = start;
            }
            tcharMap[start]++;
            if (tcharMap[start]>0) count++;
            start++;
        }
    }
    
    if (minLen == INT_MAX) return "";
    else return s.substr(minIdx, minLen);
}

#endif /* MinimumWindowSubstring_h */
