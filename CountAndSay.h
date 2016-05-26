//
//  CountAndSay.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CountAndSay_h
#define CountAndSay_h

#include "DataStructure.h"

using namespace std;

/************************************ COUNT AND SAY ***********************************/

string countAndSay(int n) {
    string prev = "1";
    string current;
    int iter = 0;
    while(iter < n - 1)
    {
        int i = 0;
        //        if (prev.length() == 1)
        //        {
        //            current += "1";
        //            current.push_back(prev[0]);
        //            continue;
        //        };
        while(i < prev.length())
        {
            int num = 0;
            while(i+1 < prev.length() && prev[i] == prev[i+1])
            {
                i++; num++;
            }
            
            current += to_string(num+1);
            current.push_back(prev[i]);
            
            i++;
        }
        
        prev = current;
        current = "";
        iter++;
    }
    
    return prev;
}

#endif /* CountAndSay_h */
