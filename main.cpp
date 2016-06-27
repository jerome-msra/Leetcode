//
//  main.cpp
//  LeetCode
//
//  Created by Jerome on 1/30/16.
//  Copyright © 2016 Jerome. All rights reserved.
//



#include "DataStructure.h"
#include "OutputHelper.h"

#include "WordBreakII.h"

using namespace std;

/****************************************** MAIN ******************************************/

int main(int argc, const char * argv[]) {
    
    string s = "catsanddog";
    
    unordered_set<string> myset{"cat","cats","and","sand","dog"};
    
    vector<string> result = wordBreak(s, myset);
    
    output1DVectorHelper(result);
    
    
    return 0;
    
    
}
