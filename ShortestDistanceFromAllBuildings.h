//
//  ShortestDistanceFromAllBuildings.h
//  LeetCode
//
//  Created by Jerome on 6/5/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ShortestDistanceFromAllBuildings_h
#define ShortestDistanceFromAllBuildings_h

#include "DataStructure.h"

using namespace std;

int shortestDistance(vector<vector<int>>& grid) {
    vector<vector<int>> distance = grid;
    queue<pair<int,int>> myqueue;
    vector<vector<int>> direction = {{-1,0},{0,-1},{0,1},{1,0}};
    int m = grid.size();
    if (m==0) return -1;
    int n = grid[0].size();
    int sign = 0;
    int result = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]==1) {
                vector<vector<int>> current = grid;
                int localMin = -1;
                myqueue.push(make_pair(i,j));
                while(!myqueue.empty()) {
                    pair<int,int> pos = myqueue.front();
                    myqueue.pop();
                    int x = pos.first, y = pos.second;
                    for (auto d : direction) {
                        int nx = x+d[0];
                        int ny = y+d[1];
                        if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==sign) {
                            grid[nx][ny]--;
                            myqueue.push(make_pair(nx,ny));
                            current[nx][ny] = current[x][y]+1;
                            distance[nx][ny] += current[nx][ny]-1;
                            localMin = localMin==-1 ? distance[nx][ny] : min(localMin, distance[nx][ny]);
                        }
                    }
                }
                
                sign--;
                
                result = localMin;
            }
        }
    }
    
    return result;
}

#endif /* ShortestDistanceFromAllBuildings_h */
