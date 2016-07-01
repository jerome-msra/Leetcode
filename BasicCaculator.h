//
//  BasicCaculator.h
//  LeetCode
//
//  Created by Jerome on 6/30/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BasicCaculator_h
#define BasicCaculator_h

#include "DataStructure.h"

using namespace std;

int calculate(string s) {
    stack<int> mystack;
    int result = 0, number = 0;
    int sign = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]>='0' && s[i]<='9') number = number * 10 + s[i]-'0';
        else if (s[i]=='+') {
            result += sign * number;
            sign = 1;
            number = 0;
        }
        else if (s[i]=='-') {
            result += sign * number;
            sign = -1;
            number = 0;
        }
        else if (s[i]=='(') {
            mystack.push(result);
            mystack.push(sign);
            sign = 1;
            result = 0;
        }
        else if (s[i]==')') {
            result += sign * number;
            number = 0;
            result *= mystack.top();
            mystack.pop();
            result += mystack.top();
            mystack.pop();
        }
    }
    
    if (number!=0) result += sign * number;
    return result;
}

#endif /* BasicCaculator_h */
