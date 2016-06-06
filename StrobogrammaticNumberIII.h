//
//  StrobogrammaticNumberIII.h
//  LeetCode
//
//  Created by Jerome on 6/5/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef StrobogrammaticNumberIII_h
#define StrobogrammaticNumberIII_h

#include "DataStructure.h"

using namespace std;

bool compareStr(string low, string high) {
    if (low.length()<high.length()) return true;
    if (low.length()>high.length()) return false;
    for (int i = 0; i < low.length(); i++) {
        if (low[i]<high[i]) return true;
        if (low[i]>high[i]) return false;
    }
    
    return true;
}

void stroboHelper(string current, int & total, string low, string high) {
    if (!compareStr(current, high)) return;
    if ((current.length()==1 || (current.length()>1 && current[0]!='0')) && compareStr(low, current) && compareStr(current, high)) {
        total++;
    }
    stroboHelper("0"+current+"0", total, low, high);
    stroboHelper("1"+current+"1", total, low, high);
    stroboHelper("6"+current+"9", total, low, high);
    stroboHelper("8"+current+"8", total, low, high);
    stroboHelper("9"+current+"6", total, low, high);
}

int strobogrammaticInRange(string low, string high) {
    vector<string> centerdigit{"", "0", "1", "8"};
    int total = 0;
    for (auto digi : centerdigit) {
        stroboHelper(digi, total, low, high);
    }
    return total;
}

#endif /* StrobogrammaticNumberIII_h */
