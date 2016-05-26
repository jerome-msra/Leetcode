//
//  LongestPalindromeSubstring.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestPalindromeSubstring_h
#define LongestPalindromeSubstring_h

#include "DataStructure.h"

using namespace std;

/****************************************** 5 LONGEST PALINDROME SUBSTRING ******************************************/

string longestPalindrome(string s) {
    if (s.length() == 0) return "";
    if (s.length() == 1) return s;
    int maxlength = 1;
    int minstart = 0;
    for (int i = 1; i < s.length() - 1; i++) {
        int j = i-1;
        int k = i+1;
        while(j >= 0 && k < s.length() && s[j] == s[k]) { j--; k++; }
        int length1 = k-j-1;
        int start1 = j+1;
        j = i-1; k = i;
        while(j >= 0 && k < s.length() && s[j] == s[k]) {j--; k++; }
        int length2 = k-j-1;
        int start2 = j+1;
        int currmaxlength = (length1 > length2) ? length1 : length2;
        int currminstart = (length1 > length2) ? start1 : start2;
        if (maxlength < currmaxlength) {
            maxlength = currmaxlength;
            minstart = currminstart;
        }
    }
    
    return s.substr(minstart, maxlength);
    
}

#endif /* LongestPalindromeSubstring_h */
