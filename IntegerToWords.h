//
//  IntegerToWords.h
//  LeetCode
//
//  Created by Jerome on 7/1/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef IntegerToWords_h
#define IntegerToWords_h

#include "DataStructure.h"

using namespace std;

vector<string> thousands{"", "Thousand", "Million", "Billion"};
vector<string> onebit{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> twobit{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tenth{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string numToWord(string threeBits) {
    size_t idx = threeBits.find_first_not_of("0");
    if (idx==string::npos) return "";
    threeBits = threeBits.substr(idx);
    string result;
    if (threeBits.length()==1) return onebit[threeBits[0]-'0'];
    if (threeBits.length()==2) {
        if (threeBits[0]=='1') return twobit[threeBits[1]-'0'];
        else {
            result += tenth[threeBits[0]-'0'];
            if (threeBits[1]>'0') result += " " + onebit[threeBits[1]-'0'];
            return result;
        }
    }
    
    if (threeBits.length()==3) {
        result += onebit[threeBits[0]-'0'] + " Hundred";
        if (threeBits[1]>'0') {
            if (threeBits[1]=='1') result += " " + twobit[threeBits[2]-'0'];
            else {
                result += " " + tenth[threeBits[1]-'0'];
                if (threeBits[2]>'0') result += " " + onebit[threeBits[2]-'0'];
            }
        }
        else {
            if (threeBits[2]>'0') result += " " + onebit[threeBits[2]-'0'];
        }
        
        return result;
    }
    
    return result;
}

string numberToWords(int num) {
    string numStr = to_string(num);
    string result;
    size_t idx = numStr.find_first_not_of("0");
    if (idx==string::npos) return "Zero";
    numStr = numStr.substr(idx);
    int thous = 0;
    while(numStr.length()>0) {
        string current;
        if (numStr.length()>=3) {
            current = numStr.substr(numStr.length()-3);
            numStr = numStr.substr(0, numStr.length()-3);
        }
        else {
            current = numStr;
            numStr = "";
        }
        
        string currWord = numToWord(current);
        if (currWord.length()>0) result = currWord + " " + thousands[thous++] + (result.length()>0 ? " " : "") + result;
        else thous++;
    }
    size_t lastidx = result.find_last_not_of(" ");
    if (lastidx!=string::npos) result = result.substr(0, lastidx+1);
    
    return result;
}



#endif /* IntegerToWords_h */
