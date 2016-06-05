//
//  EditDistance.h
//  LeetCode
//
//  Created by Jerome on 6/5/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef EditDistance_h
#define EditDistance_h

#include "DataStructure.h"

using namespace std;

int minDistance(string word1, string word2) {
    int l1 = word1.length()+1, l2 = word2.length()+1;
    vector<vector<int>> dpresult(l1, vector<int>(l2, 0));
    for (int i = 0; i < l1; i++) dpresult[i][0] = i;
    for (int i = 0; i < l2; i++) dpresult[0][i] = i;
    
    for (int i = 1; i < l1; i++) {
        for (int j = 1; j < l2; j++) {
            if (word1[i-1]==word2[j-1]) dpresult[i][j] = dpresult[i-1][j-1];
            else {
                dpresult[i][j] = min(dpresult[i-1][j-1], // transform word1[0..i-1] to word2[0..j-1] and replace word1[i]
                                     min(dpresult[i-1][j], // delete word1[i] and transform word1[0..i-1] to word2[0..j]
                                         dpresult[i][j-1])) // transform to word2[0..j] and insert word2[j]
                +1;
            }
        }
    }
    
    return dpresult[l1-1][l2-1];
}

#endif /* EditDistance_h */
