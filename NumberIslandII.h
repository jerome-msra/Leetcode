//
//  NumberIslandII.h
//  LeetCode
//
//  Created by Jerome on 6/3/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef NumberIslandII_h
#define NumberIslandII_h

#include "DataStructure.h"

using namespace std;

int root(int id, vector<int> & roots) {
    if (roots[id]==-1) return -1;
    while(id!=roots[id]) {
        roots[id] = roots[roots[id]];
        id = roots[id];
    }
    return id;
}

bool find(int p, int q, vector<int> & roots) {
    return root(p, roots)==root(q,roots);
}

void unite(int p, int q, vector<int> & roots, vector<int> & weight) {
    int pid = root(p, roots), qid = root(q, roots);
    if (weight[pid]>weight[qid]) {
        roots[qid] = pid;
        weight[pid] += weight[qid];
    }
    else {
        roots[pid] = qid;
        weight[qid] += weight[pid];
    }
}

vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> roots(m*n, -1);
    vector<int> weight(m*n, 0);
    vector<vector<int>> direction{{0,-1},{-1,0},{0,1},{1,0}};
    vector<int> result;
    int number = 0;
    for (auto coord : positions) {
        int x = coord.first, y = coord.second;
        int id = n*x+y;
        roots[id] = id;
        weight[id] = 1;
        number++;
        for (auto d : direction) {
            int nx = x + d[0];
            int ny = y + d[1];
            int nid = n*nx+ny;
            if (nx>=0 && nx<m && ny>=0 && ny<n && root(nid, roots)!=-1 && !find(nid, id, roots)) {
                unite(nid, id, roots, weight);
                number--;
            }
        }
        result.push_back(number);
    }
    
    return result;
}

#endif /* NumberIslandII_h */
