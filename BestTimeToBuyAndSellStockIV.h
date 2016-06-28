//
//  BestTimeToBuyAndSellStockIV.h
//  LeetCode
//
//  Created by Jerome on 6/28/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BestTimeToBuyAndSellStockIV_h
#define BestTimeToBuyAndSellStockIV_h

#include "DataStructure.h"

using namespace std;

/*
 
 188. Best Time to Buy and Sell Stock IV
 
 */

int maxProfitIV(int k, vector<int>& prices) {
    int n = prices.size();
    if (n<2) return 0;
    if (k>n/2) {
        int result = 0;
        for (int i = 1; i < n; i++) {
            result += max(prices[i]-prices[i-1], 0);
        }
        return result;
    }
    
    vector<int> buy(k+1, INT_MIN);
    vector<int> sell(k+1, 0);
    
    for (int i = 0; i < n; i++) {
        int p = prices[i];
        for (int j = k; j > 0; j--) {
            sell[j] = max(sell[j], buy[j]+p);
            buy[j] = max(buy[j], sell[j-1]-p);
        }
    }
    
    return sell[k];
}

#endif /* BestTimeToBuyAndSellStockIV_h */
