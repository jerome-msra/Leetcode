//
//  MultiplyString.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MultiplyString_h
#define MultiplyString_h

#include "DataStructure.h"

using namespace std;

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

/******************************************43 MULTIPLY STRINGS ******************************************/

string multiply(string num1, string num2) {
    
    if (num1 == "0" || num2 == "0") return "0";
    
    if (num1 == "1") return num2;
    
    if (num2 == "1") return num1;
    
    string result;
    
    for (int l = num2.length() - 1; l >= 0; l--) {
        int multi = num2[l] - '0';
        string currresult="0";
        for (int i = 0; i < multi; i++) {
            currresult = stringadd(num1, currresult);
        }
        for (int z = 0; z < num2.length() - l - 1; z++) currresult.push_back('0');
        result = stringadd(result, currresult);
    }
    
    return result;
}

#endif /* MultiplyString_h */
