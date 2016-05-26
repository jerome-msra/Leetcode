//
//  WordSearchII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordSearchII_h
#define WordSearchII_h

#include "Trie.h"
#include "DataStructure.h"

using namespace std;

Trie * mytrie;
int m,n;

bool findWordsHelper(vector<vector<char>> & board, vector<string> & result, string & word, int i, int j) {
    if (mytrie->search(word)) {
        result.push_back(word);
        //return true;
    }
    
    if (!mytrie->startsWith(word)) return false;
    
    bool succeed = false;
    if (i>0 && board[i-1][j]!=' ') {
        word += board[i-1][j];
        char c = board[i-1][j];
        board[i-1][j] = ' ';
        succeed = findWordsHelper(board, result, word, i-1,j);
        //        if (!succeed) { word.pop_back(); board[i-1][j] = c;}
        word.pop_back(); board[i-1][j] = c;
    }
    if (j>0 && board[i][j-1]!=' ') {
        word += board[i][j-1];
        char c = board[i][j-1];
        board[i][j-1] = ' ';
        succeed = findWordsHelper(board, result, word, i,j-1);
        //        if (!succeed) { word.pop_back(); board[i][j-1] = c;}
        word.pop_back(); board[i][j-1] = c;
    }
    if (i<m-1 && board[i+1][j]!=' ') {
        word += board[i+1][j];
        char c = board[i+1][j];
        board[i+1][j] = ' ';
        succeed = findWordsHelper(board, result, word, i+1,j);
        //        if (!succeed) { word.pop_back(); board[i+1][j] = c;}
        word.pop_back(); board[i+1][j] = c;
    }
    if (j<n-1 && board[i][j+1]!=' ') {
        word += board[i][j+1];
        char c = board[i][j+1];
        board[i][j+1] = ' ';
        succeed = findWordsHelper(board, result, word, i,j+1);
        //        if (!succeed) { word.pop_back(); board[i][j+1] = c;}
        word.pop_back(); board[i][j+1] = c;
    }
    return false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    mytrie = new Trie();
    for (auto w : words) {
        mytrie->insert(w);
    }
    vector<string> result;
    m = board.size();
    if (m==0) return result;
    n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c = board[i][j];
            string current;
            current += board[i][j];
            board[i][j] = ' ';
            findWordsHelper(board, result, current, i, j);
            board[i][j] = c;
        }
    }
    return result;
}

#endif /* WordSearchII_h */
