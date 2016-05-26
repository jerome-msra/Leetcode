//
//  AdditiveNumber.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef AdditiveNumber_h
#define AdditiveNumber_h

#include "DataStructure.h"

using namespace std;

/*********************************** 306. Additive Number **************************************/

string stringadd(string s1, string s2) {
    string sum;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int add = 0;
    for (int i = 0; i < max(s1.length(), s2.length()); i++) {
        int a = (i < s1.length()) ? s1[i] - '0' : 0;
        int b = (i < s2.length()) ? s2[i] - '0' : 0;
        int s = a+b+add;
        add = (s >= 10) ? 1 : 0;
        s = s%10;
        sum.push_back(s+'0');
    }
    if (add > 0) sum.push_back('1');
    reverse(sum.begin(), sum.end());
    return sum;
}

bool isAdditiveNumberHelper(string & num, size_t i, size_t j) {
    int start = 0;
    while(j+1 < num.length()) {
        if ((i-start>0 && num[start]=='0') || (j-i>1 && num[i+1]=='0')) break;
        string substr1 = num.substr(start, i-start+1);
        string substr2 = num.substr(i+1, j-i);
        string sum = stringadd(substr1, substr2);
        if (sum == num.substr(j+1)) return true;
        string substr3 = num.substr(j+1, sum.length());
        if (sum == substr3) {
            start = i+1;
            i = j;
            j += sum.length();
        }
        else {
            break;
        }
    }
    
    return false;
}

bool isAdditiveNumber(string num) {
    if (num.size() == 0) return false;
    for (size_t i = 0; i < num.size(); i++) {
        for (size_t j = i+1; j < num.size(); j++) {
            bool valid = isAdditiveNumberHelper(num, i, j);
            if (valid) return true;
        }
    }
    
    return false;
}

#endif /* AdditiveNumber_h */
