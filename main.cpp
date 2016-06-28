//
//  main.cpp
//  LeetCode
//
//  Created by Jerome on 1/30/16.
//  Copyright © 2016 Jerome. All rights reserved.
//



#include "DataStructure.h"
#include "OutputHelper.h"

#include "MinimumWindowSubstring.h"

using namespace std;

/****************************************** MAIN ******************************************/

int main(int argc, const char * argv[]) {
    
    string s = "aa", t = "aa";
    
    
    string x = minWindowSubstr(s, t); 
    
    std::cout << x << std::endl;
    
    return 0;
    
    
}
