//
//  WordPattern.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordPattern_h
#define WordPattern_h


#include "DataStructure.h"

using namespace std;

/****************************************** WORD PATTERN ******************************************/

bool wordPattern(string pattern, string str) {
    vector<string> strs;
    int first = 0;
    while(str[first] != ' ') first++;
    int idx = str.find_first_of(" ",first);
    int p = 0;
    while(idx != -1)
    {
        strs.push_back(str.substr(p, idx-p));
        p = idx+1;
        idx = str.find_first_of(" ", p);
    }
    
    strs.push_back(str.substr(p, str.length()));
    
    for (int i = 0; i < strs.size(); i++)
    {
        std::cout << strs[i] << std::endl;
    }
    
    map<char, string> mymap;
    
    for (int i = 0; i < pattern.length(); i++)
    {
        if (mymap.find(pattern[i]) != mymap.end())
        {
            if (mymap[pattern[i]] != strs[i])
            return false;
        }
        else
        {
            mymap[pattern[i]] = strs[i];
        }
    }
    
    
    return true;
}

#endif /* WordPattern_h */
