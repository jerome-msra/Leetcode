//
//  ExpressionAndOperator.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ExpressionAndOperator_h
#define ExpressionAndOperator_h

#include "DataStructure.h"

using namespace std;

/************************** 282. Expression Add Operators *************************/

void addOpHelper(vector<string> & result, string current, string & num, int target, int level, long sum) {
    if (level == num.length() && sum == target) {
        result.push_back(current);
        return;
    }
    for (int i = level; i < num.length(); i++) {
        string front = num.substr(level, i-level+1);
        long frontnum = atol(front.c_str());
        if (front.length()>1 && front[0]=='0') continue;
        addOpHelper(result, current+"+"+front, num, target, i+1, sum+frontnum);
        addOpHelper(result, current+"-"+front, num, target, i+1, sum-frontnum);
        addOpHelper(result, current+"*"+front, num, target, i+1, sum*frontnum);
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> result;
    if (num.length() == 0) return result;
    string current;
    if (atol(num.c_str()) == target) result.push_back(num);
    for (int i = 1; i < num.length(); i++) {
        string front = num.substr(0, i);
        long currnum = atol(front.c_str());
        addOpHelper(result, front, num, target, i, currnum);
    }
    return result;
}

#endif /* ExpressionAndOperator_h */
