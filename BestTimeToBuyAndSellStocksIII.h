//
//  BestTimeToBuyAndSellStocksIII.h
//  LeetCode
//
//  Created by Jerome on 6/28/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BestTimeToBuyAndSellStocksIII_h
#define BestTimeToBuyAndSellStocksIII_h

#include "DataStructure.h"

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy1 = INT_MIN, buy2 = INT_MIN;
    int sell1 = 0, sell2 = 0;
    for (auto p : prices) {
        buy1 = max(buy1, -p);
        sell1 = max(sell1, p+buy1);
        buy2 = max(buy2, sell1-p);
        sell2 = max(sell2, buy2+p);
    }
    
    return sell2;
}

#endif /* BestTimeToBuyAndSellStocksIII_h */
