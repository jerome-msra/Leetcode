//
//  UnlockPattern.h
//  LeetCode
//
//  Created by Jerome on 5/23/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef UnlockPattern_h
#define UnlockPattern_h

#include "DataStructure.h"

using namespace std;

void dfsHelper(int & pathNum, int num, vector<unordered_set<int>> & path, vector<bool> & visited, int step);

int lower, upper;

int numberOfPatterns(int m, int n) {
    lower = m, upper = n;
    vector<unordered_set<int>> path(10);
    path[1] = unordered_set<int>{2,4,5,6,8};
    path[2] = unordered_set<int>{1,3,4,5,6,7,9};
    path[3] = unordered_set<int>{2,4,5,6,8};
    path[4] = unordered_set<int>{1,2,3,5,7,8,9};
    path[5] = unordered_set<int>{1,2,3,4,6,7,8,9};
    path[6] = unordered_set<int>{1,2,3,5,7,8,9};
    path[7] = unordered_set<int>{2,4,5,6,8};
    path[8] = unordered_set<int>{1,3,4,5,6,7,9};
    path[9] = unordered_set<int>{2,4,5,6,8};
    vector<bool> visited(10, false);
    int result = 0;
    for (int s = 1; s <= 9; s++) {
        std::cout << s << std::endl;
        vector<bool> visited(10, false);
        int pathNum = 0;
        vector<unordered_set<int>> originPath = path;
        dfsHelper(pathNum, s, originPath, visited, 1);
        result += pathNum;
    }
    
    return result;
}

void addPath(int num, vector<unordered_set<int>> & path) {
    switch(num) {
        case 2:
            path[1].insert(3);
            path[3].insert(1);
            break;
        case 4:
            path[1].insert(7);
            path[7].insert(1);
            break;
        case 5:
            path[1].insert(9);
            path[2].insert(8);
            path[3].insert(7);
            path[4].insert(6);
            path[6].insert(4);
            path[7].insert(3);
            path[8].insert(2);
            path[9].insert(1);
            break;
        case 6:
            path[3].insert(9);
            path[9].insert(3);
            break;
        case 8:
            path[7].insert(9);
            path[9].insert(7);
            break;
        default:
            break;
    }
}

void removePath(int num, vector<unordered_set<int>> & path) {
    switch(num) {
        case 2:
            path[1].erase(3);
            path[3].erase(1);
            break;
        case 4:
            path[1].erase(7);
            path[7].erase(1);
            break;
        case 5:
            path[1].erase(9);
            path[2].erase(8);
            path[3].erase(7);
            path[4].erase(6);
            path[6].erase(4);
            path[7].erase(3);
            path[8].erase(2);
            path[9].erase(1);
            break;
        case 6:
            path[3].erase(9);
            path[9].erase(3);
            break;
        case 8:
            path[7].erase(9);
            path[9].erase(7);
            break;
        default:
            break;
    }
}

void dfsHelper(int & pathNum, int num, vector<unordered_set<int>> & path, vector<bool> & visited, int step) {
    if (step>upper) return;
    if (step >=lower && step <= upper) pathNum++;
    visited[num] = true;
    addPath(num, path);
    for (auto next : path[num]) {
        if (!visited[next]) {
            dfsHelper(pathNum, next, path, visited, step+1);
        }
    }
    visited[num] = false;
    removePath(num, path);
}


#endif /* UnlockPattern_h */
