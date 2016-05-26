//
//  PermutationSequence.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PermutationSequence_h
#define PermutationSequence_h

#include "DataStructure.h"

using namespace std;

/*********************************** 60. PERMUTATION SEQUENCE **************************************/

int total;
int target;

string getPermutationHelper(int & k, string & perm, int level) {
    if (perm.length() == total) {
        k++;
        if (k == target) return perm;
        else return "";
    }
    for (int i = 1; i<=total; i++) {
        if (i != level)
            perm.push_back(i+'0');
        string xy = getPermutationHelper(k, perm, i+1);
        if (xy != "") {
            return xy;
        }
        else {
            perm.pop_back();
        }
    }
    
    return "";
}

string getPermutation(int n, int k) {
    if (n == 1) return "1";
    string permu;
    total = n;
    target = k;
    int x = 0;
    string result = getPermutationHelper(x, permu, 1);
    return result;
}

#endif /* PermutationSequence_h */
