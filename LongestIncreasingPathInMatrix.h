//
//  LongestIncreasingPathInMatrix.h
//  LeetCode
//
//  Created by Jerome on 6/4/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestIncreasingPathInMatrix_h
#define LongestIncreasingPathInMatrix_h

#include "DataStructure.h"

using namespace std;

vector<vector<int>> direction = {{-1,0},{0,-1},{1,0},{0,1}};

int dfsVisit(vector<vector<int>> & matrix, vector<vector<int>> & visited, int i, int j, int m, int n) {
    int maxdist = 1;
    for (auto d : direction) {
        int ni = i + d[0];
        int nj = j + d[1];
        if (ni>=0 && ni<m && nj>=0 && nj<n && matrix[ni][nj]>matrix[i][j]) {
            if (visited[ni][nj] == 0) {
                int d = dfsVisit(matrix, visited, ni, nj, m, n);
                maxdist = max(maxdist, d+1);
            }
            else {
                maxdist = max(maxdist, visited[ni][nj]+1);
            }
        }
    }
    visited[i][j] = maxdist;
    return maxdist;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxLength = 1;
    int m = matrix.size();
    if (m==0) return 0;
    int n = matrix[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]==0) {
                int d = dfsVisit(matrix, visited, i, j, m, n);
                visited[i][j] = d;
                std::cout << i << " " << j << " " << d << std::endl;
                maxLength = max(maxLength, d);
            }
        }
    }
    
    return maxLength;
}

#endif /* LongestIncreasingPathInMatrix_h */
