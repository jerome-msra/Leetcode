//
//  RemoveInvalidParenthesis.h
//  LeetCode
//
//  Created by Jerome on 6/5/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RemoveInvalidParenthesis_h
#define RemoveInvalidParenthesis_h

#include "DataStructure.h"

using namespace std;

bool isValid(string s) {
    int left = 0;
    for (auto c : s) {
        if (c=='(') left++;
        if (c==')') left--;
        if (left<0) return false;
    }
    return left==0;
}

vector<string> removeInvalidParentheses(string s) {
    queue<string> myqueue;
    myqueue.push(s);
    unordered_set<string> resultset;
    unordered_set<string> visited;
    visited.insert(s);
    bool flag = false;
    while(!myqueue.empty()) {
        string qs = myqueue.front();
        myqueue.pop();
        if (isValid(qs)) {
            resultset.insert(qs);
            flag = true;
        }
        if (flag) continue; // stop searching next level
        
        for (int j = 0; j < qs.length(); j++) {
            if (qs[j]!='(' && qs[j]!=')') continue;
            
            string checkStr = qs.substr(0,j)+qs.substr(j+1);
            if (visited.count(checkStr)==0) {
                visited.insert(checkStr);
                myqueue.push(checkStr);
            }
        }
    }
    
    vector<string> result(resultset.begin(), resultset.end());
    return result;
}

#endif /* RemoveInvalidParenthesis_h */
