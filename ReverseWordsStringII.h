//
//  ReverseWordsStringII.h
//  LeetCode
//
//  Created by Jerome on 5/22/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ReverseWordsStringII_h
#define ReverseWordsStringII_h

#include "DataStructure.h"

using namespace std;

void reverseWordsII(string &s) {
    int start = 0, end = s.length()-1;
    while(start < end) {
        while(start < s.length() && s[start]==' ') start++;
        int startpos = start;
        while(start < s.length() && s[start]!=' ') start++;
        string s1 = s.substr(startpos, start-startpos);
        while(end >= 0 && s[end]==' ') end--;
        int endpos = end;
        while(end >= 0 && s[end]!=' ') end--;
        string s2 = s.substr(end+1, endpos-end);
        s.replace(startpos, start-startpos, s2);
        end += s2.length()-s1.length();
        endpos += s2.length()-s1.length();
        s.replace(end+1, endpos-end, s1);
        start += s2.length()-s1.length();
        
    }
    
    return;
}


#endif /* ReverseWordsStringII_h */
