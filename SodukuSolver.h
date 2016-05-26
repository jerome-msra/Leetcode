//
//  SodukuSolver.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SodukuSolver_h
#define SodukuSolver_h

#include "DataStructure.h"

using namespace std;

/************************** 37. Sudoku Solver *************************/

bool solveHelper(vector<vector<char>> & board, vector<pair<int,int>> & toFill, vector<unordered_set<int>> & rowSet, vector<unordered_set<int>> & colSet, vector<unordered_set<int>> & gridSet, int level) {
    if (level >= toFill.size()) return true;
    for (int i = 1; i <= 9; i++) {
        pair<int,int> coord = toFill[level];
        int x = coord.first, y = coord.second;
        if (rowSet[x].count(i)==0 && colSet[y].count(i)==0 && gridSet[3*(x/3)+(y/3)].count(i)==0) {
            board[x][y] = '0'+i;
            rowSet[x].insert(i); colSet[y].insert(i); gridSet[3*(x/3)+(y/3)].insert(i);
            if (!solveHelper(board, toFill, rowSet, colSet, gridSet, level+1)) {
                board[x][y]='.';
                rowSet[x].erase(i); colSet[y].erase(i); gridSet[3*(x/3)+(y/3)].erase(i);
            }
            else {
                return true;
            }
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    vector<unordered_set<int>> rowSet(9), colSet(9), gridSet(9);
    vector<pair<int,int>> toFill;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            auto gridNum = [](int i, int j) {return 3 * (i/3) + (j/3);};
            if (board[i][j] == '.') toFill.push_back(pair<int,int>(i,j));
            else {
                rowSet[i].insert(board[i][j]-'0');
                colSet[j].insert(board[i][j]-'0');
                gridSet[gridNum(i,j)].insert(board[i][j]-'0');
            }
        }
    }
    solveHelper(board, toFill, rowSet, colSet, gridSet, 0);
    return;
}

#endif /* SodukuSolver_h */
