//
//  NQueensII.h
//  LeetCode
//
//  Created by Jerome on 6/2/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef NQueensII_h
#define NQueensII_h

#include "DataStructure.h"

using namespace std;

void nqueenHelper(vector<bool> & cols, vector<bool> & diag, vector<bool> & anti, int q, int n, int & result) {
    if (q>=n) {
        result++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cols[i] && diag[i+q] && anti[q+n-i-1]) {
            //std::cout << i << " " << j << std::endl;
            cols[i]=false;
            diag[i+q]=false;
            anti[q+n-i-1]=false;
            nqueenHelper(cols, diag, anti, q+1, n, result);
            cols[i]=true;
            diag[i+q]=true;
            anti[q+n-i-1]=true;
        }
    }
}

int totalNQueens(int n) {
    vector<bool> cols(n, true);
    vector<bool> diag(2*n-1, true);
    vector<bool> anti(2*n-1, true);
    int result = 0;
    nqueenHelper(cols, diag, anti, 0, n, result);
    return result;
}

#endif /* NQueensII_h */
