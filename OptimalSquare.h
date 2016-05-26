//
//  OptimalSquare.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef OptimalSquare_h
#define OptimalSquare_h

#include "DataStructure.h"

using namespace std;

/*********************************** 221 Maximal Square **************************************/

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;
    vector<vector<int>> dpresult(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        dpresult[i][0] = matrix[i][0] - '0';
    }
    for (int i = 0; i < matrix[0].size(); i++) {
        dpresult[0][i] = matrix[0][i] - '0';
    }
    int maxsize = 0;
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
            if (matrix[i][j] == '1') {
                dpresult[i][j] = min(dpresult[i][j-1], min(dpresult[i-1][j], dpresult[i-1][j-1])) + 1;
                maxsize = max(maxsize, dpresult[i][j]);
            }
            else {
                dpresult[i][j] = 0;
            }
        }
    }
    
    return maxsize * maxsize;
}

#endif /* OptimalSquare_h */
