//
//  SparseMatrixMultiplication.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SparseMatrixMultiplication_h
#define SparseMatrixMultiplication_h

#include "DataStructure.h"

using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    size_t m = A.size();
    size_t n = A[0].size();
    size_t Bn = B[0].size();
    vector<unordered_map<int,int>> sparseA(m);
    vector<unordered_map<int,int>> sparseB(m);
    vector<vector<int>> result(m, vector<int>(Bn, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j]!=0) sparseA[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (B[j][i]!=0) sparseB[j][i] = B[j][i];
        }
    }
    
    for (int i = 0; i < sparseA.size(); i++) {
        for (auto mapit : sparseA[i]) {
            int idx = mapit.first;
            for (int j = 0; j < sparseB.size(); j++) {
                if (sparseB[j].find(idx)!=sparseB[j].end()) {
                    result[i][j] += mapit.second * sparseB[j][idx];
                }
            }
        }
    }
    
    return result;
}

#endif /* SparseMatrixMultiplication_h */
