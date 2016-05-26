//
//  ValidSoduku.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ValidSoduku_h
#define ValidSoduku_h

#include "DataStructure.h"

using namespace std;

/****************************************** VALID SUDOKU ***********************************************/

bool check(vector<bool> & checker, char c)
{
    if (checker[c - '1']) return false;
    if (c == '.') return true;
    if (checker[c - '1'] == false)
    {
        checker[c-'1'] = true;
        return true;
    }
    
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++)
    {
        vector<bool> checker(9, false);
        for (int j = 0; j < 9; j++)
        {
            if (check(checker, board[i][j]) == false)
            return false;
        }
    }
    
    for (int i = 0; i < 9; i++)
    {
        vector<bool> checker(9, false);
        for (int j = 0; j < 9; j++)
        {
            if (check(checker, board[j][i]) == false)
            return false;
        }
    }
    
    for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
    {
        vector<bool> checker(9, false);
        for (int i = r * 3; i < r * 3 + 3; i++)
        for (int j = c * 3; j < c * 3 + 3; j++)
        {
            if (check(checker, board[i][j]) == false)
            return false;
        }
    }
    
    return true;
}

#endif /* ValidSoduku_h */
