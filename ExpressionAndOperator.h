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

/*
 What to learn:
 
 the method to process the multiply(*) operator
 
 */


/************************** 282. Expression Add Operators *************************/

void addOpHelper(vector<string> & result, string current, long leftNum, string & num, int level, int target, long multi, int depth);

vector<string> addOperators(string num, int target) {
    vector<string> result;
    for (int i = 1; i <= num.length(); i++) {
        string left = num.substr(0, i);
        if (left.length()>1 && left[0]=='0') continue;
        long leftNum = stol(left);
        addOpHelper(result, left, leftNum, num, i, target, 0, 0);
    }
    
    return result;
}

void addOpHelper(vector<string> & result, string current, long leftNum, string & num, int level, int target, long multi, int depth) {
    if (level==num.length() && leftNum==target) {
        result.push_back(current);
        return;
    }
    
    for (int i = 1; i <= num.length()-level; i++) {
        string curr = num.substr(level, i);
        if (curr.length()>1 && curr[0]=='0') continue;
        long currNum = stol(curr);
        addOpHelper(result, current+"+"+curr, leftNum+currNum, num, level+i, target, currNum, depth+1);
        addOpHelper(result, current+"-"+curr, leftNum-currNum, num, level+i, target, -currNum, depth+1);
        if (depth==0) {
            addOpHelper(result, current+"*"+curr, leftNum*currNum, num, level+i, target, leftNum*currNum, depth+1);
        }
        else {
            addOpHelper(result, current+"*"+curr, leftNum-multi + multi*currNum, num, level+i, target, multi*currNum, depth+1);
        }
    }
}

#endif /* ExpressionAndOperator_h */
