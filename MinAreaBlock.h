//
//  MinAreaBlock.h
//  LeetCode
//
//  Created by Jerome on 5/24/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MinAreaBlock_h
#define MinAreaBlock_h

#include "DataStructure.h"

using namespace std;

int minArea(vector<vector<char>>& image, int x, int y) {
    int m = image.size();
    if (m==0) return 0;
    int n = image[0].size();
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(x,y));
    int minx = x, maxx = x, miny = y, maxy = y;
    image[x][y] = '0';
    while(!myqueue.empty()) {
        pair<int,int> coord = myqueue.front();
        std::cout << myqueue.size() << std::endl;
        myqueue.pop();
        int xc = coord.first, yc = coord.second;
        minx = min(minx, xc);
        maxx = max(maxx, xc);
        miny = min(miny, yc);
        maxy = max(maxy, yc);
        if (xc>0 && image[xc-1][yc]=='1') { myqueue.push(make_pair(xc-1,yc)); image[xc-1][yc]='0'; }
        if (yc>0 && image[xc][yc-1]=='1') { myqueue.push(make_pair(xc,yc-1)); image[xc][yc-1]='0'; }
        if (xc+1<m && image[xc+1][yc]=='1') { myqueue.push(make_pair(xc+1,yc)); image[xc+1][yc]='0'; }
        if (yc+1<n && image[xc][yc+1]=='1') { myqueue.push(make_pair(xc,yc+1)); image[xc][yc+1]='0'; }
    }
    
    return (maxx-minx+1)*(maxy-miny+1);
}

#endif /* MinAreaBlock_h */
