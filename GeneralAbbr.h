//
//  GeneralAbbr.h
//  LeetCode
//
//  Created by Jerome on 5/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef GeneralAbbr_h
#define GeneralAbbr_h

#include "DataStructure.h"

using namespace std;

vector<string> generateAbbreviations(string word) {
    int len = word.length();
    int total = 1<<len;
    vector<string> result;
    for (int i = 0; i < total; i++) {
        string w = word;
        int x = i;
        int tbit = len-1;
        while(x>0) {
            int temp = 0;
            while(!(x&1)) {
                x = x>>1;
                tbit--;
            }
            while(x&1) {
                x = x>>1;
                temp++;
            }
            tbit -= temp-1;
            w.replace(tbit,temp, to_string(temp));
            tbit--;
        }
        result.push_back(w);
    }
    return result;
}

#endif /* GeneralAbbr_h */
