//
//  WordSearch.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordSearch_h
#define WordSearch_h

#include "DataStructure.h"

using namespace std;

/****************************************** 79 WORD SEARCH ******************************************/

string m_word;

bool dfsBoard(vector<vector<char>> & board, int i, int j, int pos, vector<vector<int>> visited) {
    if (board[i][j] == m_word[pos] && pos == m_word.length() - 1)
        return true;
    if (board[i][j] != m_word[pos])
        return false;
    if (board[i][j] == m_word[pos])
        visited[i][j] = 1;
    
    bool left = false,right = false,up = false, down = false;
    if (i-1 >= 0 && !visited[i-1][j]) {
        left = dfsBoard(board, i-1, j, pos+1, visited);
        if (!left) {
            if (i+1 < board.size() && !visited[i+1][j]) {
                right = dfsBoard(board, i+1, j, pos+1, visited);
                if (!right) {
                    if (j-1 >= 0 && !visited[i][j-1]) {
                        up = dfsBoard(board, i, j-1, pos+1, visited);
                        if (!up) {
                            if (j+1 < board[0].size() && !visited[i][j+1]) {
                                down = dfsBoard(board, i, j+1, pos+1, visited);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return left || right || up || down;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) return word.empty();
    if (word.size() == 0) return true;
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
    m_word = word;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                bool res = dfsBoard(board, i, j, 0, visited);
                if (res) return true;
            }
        }
    }
    
    return false;
}

#endif /* WordSearch_h */
