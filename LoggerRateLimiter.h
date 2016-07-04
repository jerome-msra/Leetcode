//
//  LoggerRateLimiter.h
//  LeetCode
//
//  Created by Jerome on 7/3/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LoggerRateLimiter_h
#define LoggerRateLimiter_h


#include "DataStructure.h"

using namespace std;

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
     If this method returns false, the message will not be printed.
     The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (stringMap.find(message)==stringMap.end()) {
            stringMap[message] = timestamp;
            return true;
        }
        else {
            if (timestamp - stringMap[message]>=10) {
                stringMap[message] = timestamp;
                return true;
            }
            else return false;
        }
    }
    
    unordered_map<string, int> stringMap;
};

#endif /* LoggerRateLimiter_h */
