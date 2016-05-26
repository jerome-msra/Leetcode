//
//  Triangle.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

#include "DataStructure.h"

using namespace std;

/********************************************* 120 TRIANGLE ******************************************/

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 0) return 0;
    vector<vector<int>> result;
    result.resize(triangle.size());
    for (int i = 0; i < triangle.size(); i++) {
        result[i].resize(triangle[i].size());
    }
    
    result[0][0] = triangle[0][0];
    for (int i = 1; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            int a = INT_MAX,b = INT_MAX,c = INT_MAX;
            if (j-1>=0) a = result[i-1][j-1]+triangle[i][j];
            if (j < result[i-1].size()) b = result[i-1][j] + triangle[i][j];
            if (j+1 < result[i-1].size()) b = result[i-1][j+1] + triangle[i][j];
            result[i][j] = min(c,min(a,b));
        }
    }
    int path = INT_MAX;
    for (int i = 0; i < result[result.size() - 1].size(); i++) {
        path = (path > result[result.size() - 1][i]) ? result[result.size() - 1][i] : path;
    }
    
    return path;
}

#endif /* Triangle_h */
