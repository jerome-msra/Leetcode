//
//  NumOfIslands.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef NumOfIslands_h
#define NumOfIslands_h

#include "DataStructure.h"

using namespace std;

/*********************************** 200 NUM OF ISLANDS **************************************/

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int result = 0;
    if (grid.size() == 0) return result;
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '0') continue;
            queue<pair<int,int>> myqueue;
            myqueue.push(pair<int,int>(i,j));
            grid[i][j] = '0';
            while(!myqueue.empty()) {
                pair<int,int> current = myqueue.front();
                myqueue.pop();
                int row = current.first;
                int col = current.second;
                grid[row][col] = '0';
                if (row>0 && grid[row-1][col]=='1') { grid[row-1][col] = '0'; myqueue.push(pair<int,int>(row-1, col)); }
                if (col>0 && grid[row][col-1]=='1') { grid[row][col-1] = '0'; myqueue.push(pair<int,int>(row, col-1)); }
                if (row < n-1 && grid[row+1][col]=='1') { grid[row+1][col] = '0'; myqueue.push(pair<int,int>(row+1,col)); }
                if (col < n-1 && grid[row][col+1]=='1') {grid[row][col+1] = '0'; myqueue.push(pair<int,int>(row,col+1)); }
            }
            result++;
        }
    }
    
    return result;
}

#endif /* NumOfIslands_h */
