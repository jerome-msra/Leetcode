//
//  NQueens.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef NQueens_h
#define NQueens_h

#include "DataStructure.h"

using namespace std;

/************************** N-QUEENS *************************/

int nqueen;

bool nQueensHelper(vector<vector<string>> & result, vector<string> & current, vector<int> & colume,
                   vector<int> & diag, vector<int> & antidiag, int q) {
    
    if (q >= nqueen) {
        result.push_back(current);
        return true;
    }
    
    for (int i = 0; i < nqueen; i++) {
        if (colume[i]==0 && diag[i+q]==0 && antidiag[nqueen-i-1+q]==0) {
            current[q][i]='Q';
            colume[i]=1; diag[i+q]=1; antidiag[nqueen-i-1+q]=1;
            nQueensHelper(result, current, colume, diag, antidiag, q+1);
            //            if (!nQueensHelper(result, current, colume, diag, antidiag, q+1)) {
            current[q][i]='.';
            colume[i]=0; diag[i+q]=0; antidiag[nqueen-i-1+q]=0;
            //            }
        }
    }
    
    return false;
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> current(n, string(n,'.'));
    vector<vector<string>> result;
    nqueen = n;
    vector<int> colume(n, 0);
    vector<int> diag(2*n-1, 0);
    vector<int> antidiag(2*n-1, 0);
    nQueensHelper(result, current, colume, diag, antidiag, 0);
    return result;
}

#endif /* NQueens_h */
