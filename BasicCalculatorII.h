//
//  BasicCalculatorII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BasicCalculatorII_h
#define BasicCalculatorII_h

#include "DataStructure.h"

using namespace std;

/*********************************** 227. BASIC CALCULATOR II **************************************/

int calculate(string s) {
    stack<int> numstack;
    stack<char> symstack;
    int pos = 0;
    while(pos < s.length()) {
        while(pos < s.length() && s[pos]==' ') pos++;
        if (pos >= s.length()) break;
        if (s[pos] >= '0' && s[pos] <= '9') {
            int numstart = pos;
            while(pos < s.length() && s[pos] >= '0' && s[pos] <= '9') pos++;
            string currentnumstr = s.substr(numstart, pos-numstart);
            int currentnum = atoi(currentnumstr.c_str());
            if (symstack.empty() || symstack.top() == '+' || symstack.top() == '-')
                numstack.push(currentnum);
            else {
                char sym = symstack.top();
                symstack.pop();
                int prevnum = numstack.top();
                numstack.pop();
                if (sym == '*') numstack.push(prevnum * currentnum);
                else if (sym == '/') numstack.push(prevnum / currentnum);
            }
        }
        else {
            symstack.push(s[pos]);
            pos++;
        }
    }
    
    stack<char> revsymstack;
    stack<int> revnumstack;
    while(!symstack.empty()) {
        revsymstack.push(symstack.top());
        symstack.pop();
    }
    
    while(!numstack.empty()) {
        revnumstack.push(numstack.top());
        numstack.pop();
    }
    
    symstack = revsymstack;
    numstack = revnumstack;
    
    while(!symstack.empty()) {
        int num2 = numstack.top();
        numstack.pop();
        int num1 = numstack.top();
        numstack.pop();
        char symbol = symstack.top();
        symstack.pop();
        if (symbol == '+') numstack.push(num1+num2);
        else if (symbol == '-') numstack.push(num1-num2);
    }
    
    return numstack.top();
};

#endif /* BasicCalculatorII_h */
