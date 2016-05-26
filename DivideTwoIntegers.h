//
//  DivideTwoIntegers.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef DivideTwoIntegers_h
#define DivideTwoIntegers_h

#include "DataStructure.h"

using namespace std;


/******************************** 29. Divide Two Integers *********************************/

int divide(int dividend, int divisor) {
    int a = dividend, b = divisor;
    long result = 0;
    int i = 0;
    while(a >= b) {
        i = 0;
        while(a >= b<<i) {
            a -= b<<i;
            result += 1<<i;
            i++;
        }
    }
    
    return result;
}

string fractionToDecimal(int numerator, int denominator) {
    int sign = (numerator>0 && denominator>0) || (numerator<0 && denominator<0);
    unsigned long top = labs(numerator), bot = labs(denominator);
    unsigned long intenter = top / bot;
    
    top -= intenter * bot;
    if (top == 0) return to_string(intenter);
    
    string fraction;
    unordered_map<unsigned long, int> remMap;
    remMap[top] = 0;
    int i = 1;
    top*=10;
    while(top < bot) {
        remMap[top] = i;
        top*=10;
        fraction.push_back('0');
        i++;
    }
    
    std::cout << top << std::endl;
    
    bool loop = false;
    int looppos = 0;
    while(true) {
        unsigned long divd = top / bot;
        unsigned long remainder = top - divd * bot;
        if (remainder == 0) {
            fraction.push_back('0'+divd);
            loop = false;
            break;
        }
        auto it = remMap.find(remainder);
        if (it == remMap.end()) {
            fraction.push_back('0'+divd);
            remMap[remainder] = i;
            i++;
        }
        else {
            fraction.push_back('0'+divd);
            looppos = it->second;
            loop = true;
            break;
        }
        remainder*=10;
        while(remainder<bot) {
            remainder *= 10;
            fraction.push_back('0');
            i++;
        }
        top = remainder;
    }
    
    std::cout << fraction << std::endl;
    std::cout << looppos << std::endl;
    string result;
    if (!sign) result.push_back('-');
    
    if (!loop) {
        result += to_string(intenter);
        result.push_back('.');
        result += fraction;
    }
    else {
        result += to_string(intenter);
        result.push_back('.');
        result += fraction.substr(0, looppos);
        result.push_back('(');
        result += fraction.substr(looppos);
        result.push_back(')');
    }
    
    return result;
}

#endif /* DivideTwoIntegers_h */
