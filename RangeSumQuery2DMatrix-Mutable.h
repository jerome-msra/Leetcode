//
//  RangeSumQuery2DMatrix-Mutable.h
//  LeetCode
//
//  Created by Jerome on 7/2/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RangeSumQuery2DMatrix_Mutable_h
#define RangeSumQuery2DMatrix_Mutable_h

#include "DataStructure.h"

using namespace std;

class RangeSumQuery2DMatrixMutable {
public:
    NumMatrix(vector<vector<int>> &matrix) : mat(matrix) {
        m = matrix.size();
        if (m==0) return;
        n = matrix[0].size();
        bitTree = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                updateDiff(i, j, matrix[i][j]);
            }
        }
    }
    
    void updateDiff(int row, int col, int diff) {
        row++;
        col++;
        for (int i = row; i <= m; i+=(i&-i)) {
            for (int j = col; j <= n; j+=(j&-j)) {
                bitTree[i][j] += diff;
            }
        }
    }
    
    void update(int row, int col, int val) {
        updateDiff(row, col, val-mat[row][col]);
        mat[row][col] = val;
    }
    
    int getSum(int row, int col) {
        int result = 0;
        row++;
        col++;
        for (int i = row; i>0; i-=(i&-i)) {
            for (int j = col; j>0; j-=(j&-j)) {
                result += bitTree[i][j];
            }
        }
        
        return result;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row1-1, col2) - getSum(row2, col1-1) + getSum(row1-1, col1-1);
    }
    
    int m, n;
    vector<vector<int>> bitTree;
    vector<vector<int>> & mat;
};

#endif /* RangeSumQuery2DMatrix_Mutable_h */
