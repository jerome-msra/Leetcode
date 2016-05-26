//
//  LargestNumber.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LargestNumber_h
#define LargestNumber_h

#include "DataStructure.h"

using namespace std;

/*********************************** 179. Largest Number **********************************/

bool stringCompare(string s1, string s2) {
    //    int i = 0;
    //    for (i = 0; i < min(s1.length(), s2.length()); i++) {
    //        if (s1[i] < s2[i]) return true;
    //        else if (s1[i] > s2[i]) return false;
    //    }
    //
    //    string shortstr = (i == s1.length()) ? s1 : s2;
    //    string longstr = (i == s1.length()) ? s2 : s1;
    //    int j = 0;
    //    while(j < shortstr.length() && i < longstr.size()) {
    //        if (shortstr[i]>longstr[i]) return longstr == s1;
    //        if (shortstr[i]<longstr[i]) return shortstr == s1;
    //    }
    string comb1 = s1+s2;
    string comb2 = s2+s1;
    return comb1 > comb2;
}

string largestNumber(vector<int>& nums) {
    stringstream iss;
    vector<string> strnums;
    for (auto it : nums) {
        strnums.push_back(to_string(it));
    }
    sort(strnums.begin(), strnums.end(), stringCompare);
    //reverse(strnums.begin(), strnums.end());
    
    for (auto it : strnums) {
        iss << it;
    }
    return iss.str();
}

#endif /* LargestNumber_h */
