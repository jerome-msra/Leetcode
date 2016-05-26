//
//  SurroundedRegions.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SurroundedRegions_h
#define SurroundedRegions_h

#include "DataStructure.h"

using namespace std;

/**************************** 130	Surrounded Regions ******************************/

void solve(vector<vector<char>>& board) {
    if (board.size() == 0) return;
    set<pair<int,int>> visited;
    queue<pair<int,int>> myqueue;
    for (int i = 0; i < board.size(); i++) {
        int j = 0;
        while(j < board[i].size()) {
            
            char c = board[i][j];
            if (c == 'O') {
                myqueue.push(make_pair(i,j));
                visited.insert(make_pair(i,j));
                while(!myqueue.empty()) {
                    auto it = myqueue.front();
                    int x = it.first;
                    int y = it.second;
                    myqueue.pop();
                    if (x>0 && board[x-1][y]=='O' && visited.count(make_pair(x-1,y)) == 0) {
                        visited.insert(make_pair(x-1,y));
                        myqueue.push(make_pair(x-1,y));
                    }
                    if (x+1<board.size() && board[x+1][y]=='O' && visited.count(make_pair(x+1,y)) == 0) {
                        visited.insert(make_pair(x+1,y));
                        myqueue.push(make_pair(x+1,y));
                    }
                    if (y>0 && board[x][y-1]=='O' && visited.count(make_pair(x,y-1)) == 0) {
                        visited.insert(make_pair(x,y-1));
                        myqueue.push(make_pair(x,y-1));
                    }
                    if (y+1<board[x].size() && board[x][y+1]=='O' && visited.count(make_pair(x,y+1)) == 0) {
                        visited.insert(make_pair(x,y+1));
                        myqueue.push(make_pair(x,y+1));
                    }
                }
            }
            
            j += (i==0 || i == board.size()-1) ? 1 : board[i].size()-1;
        }
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O' && visited.count(make_pair(i,j)) == 0) {
                board[i][j] = 'X';
            }
        }
    }
}

#endif /* SurroundedRegions_h */
