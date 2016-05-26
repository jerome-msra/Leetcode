//
//  main.cpp
//  LeetCode
//
//  Created by Jerome on 1/30/16.
//  Copyright © 2016 Jerome. All rights reserved.
//



#include "DataStructure.h"
#include "OutputHelper.h"

#include "AlienOrder.h"

using namespace std;

/****************************************** MAIN ******************************************/

int main(int argc, const char * argv[]) {
    
    vector<string> dict{"a", "b", "a"};
    
    string result = alienOrder(dict);
    
    std::cout << result << std::endl;
    
    return 0;
    
    
}
