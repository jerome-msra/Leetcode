//
//  ZigZag.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ZigZag_h
#define ZigZag_h

#include "DataStructure.h"

using namespace std;

/****************************************** ZIG ZAG CONVERSION ******************************************/

string convert(string s, int numRows) {
    vector<vector<char>> mat;
    mat.resize(numRows);
    int numCol = s.length() / (2 * numRows - 2);
    numCol *= numRows - 1;
    numCol += s.length() % (2 * numRows - 2);
    for (int i = 0; i < numRows; i++)
    {
        mat[i].resize(numCol, ' ');
    }
    for (int i = 0; i < s.length(); i++)
    {
        int tmp_x = i % (2 * numRows - 2);
        int idx_x = (tmp_x < numRows) ? tmp_x : (2 * numRows - tmp_x - 2);
        int tmp_y = i / (2 * numRows - 2);
        int idx_y = tmp_y * (numRows - 1);
        idx_y += tmp_x < numRows ? 0 : (tmp_x - numRows + 1);
        mat[idx_x][idx_y] = s[i];
    }
    
    output2DMatHelper(mat);
    
    string result;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCol; j++)
        {
            if (mat[i][j] != ' ')
            result.push_back(mat[i][j]);
        }
    }
    
    return result;
}

#endif /* ZigZag_h */
