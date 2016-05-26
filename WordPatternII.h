//
//  WordPatternII.h
//  LeetCode
//
//  Created by Jerome on 5/25/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordPatternII_h
#define WordPatternII_h

#include "DataStructure.h"

using namespace std;

bool matchHelper(unordered_map<char, string> & p2str, unordered_map<string, char> & str2p, string & pattern, string & str, int pid, int sid, int minm) {
    
    char p = pattern[pid];
    
    if (p2str.find(p)!=p2str.end()) {
        string prev = p2str[p];
        string s = str.substr(sid, prev.length());
        if (s!=prev) return false;
        if (pid==pattern.length()-1) return true;
        return matchHelper(p2str, str2p, pattern, str, pid+1, sid+prev.length(), minm);
    }
    else {
        if (pid==pattern.length()-1) {
            string s = str.substr(sid);
            return str2p.find(s)==str2p.end();
        }
        for (int i = minm; sid+i<str.length(); i++) {
            string s = str.substr(sid, i);
            if (str2p.find(s)!=str2p.end()) continue;
            p2str[p] = s;
            str2p[s] = p;
            if (!matchHelper(p2str, str2p, pattern, str, pid+1, sid+i, minm))
            {
                p2str.erase(p);
                str2p.erase(s);
            }
            else{
                return true;
            }
        }
        
        return false;
    }
}

bool wordPatternMatch(string pattern, string str) {
    if (str.length() < pattern.length()) return false;
    if (str.length()==0 && pattern.length()==0) return true;
    else if (pattern.length()==0) return false;
    unordered_map<char, string> p2str;
    unordered_map<string, char> str2p;
    int minm = str.length() / pattern.length();
    
    return matchHelper(p2str, str2p, pattern, str, 0, 0, minm);
}



#endif /* WordPatternII_h */
