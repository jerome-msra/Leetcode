//
//  CompareVersion.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CompareVersion_h
#define CompareVersion_h

#include "DataStructure.h"

using namespace std;

/****************************************** compare Version ******************************************/

int compareVersion(string version1, string version2) {
    int pos1 = 0; int pos2 = 0;
    int idx1 = 0; int idx2 = 0;
    while(pos1 < version1.length() && pos2 < version2.length())
    {
        idx1 = version1.find_first_of(".", pos1);
        idx2 = version2.find_first_of(".", pos2);
        idx1 = (idx1 == -1) ? version1.length() : idx1;
        idx2 = (idx2 == -1) ? version2.length() : idx2;
        string v1 = version1.substr(pos1, idx1-pos1);
        string v2 = version2.substr(pos2, idx2-pos2);
        if (atoi(v1.c_str()) > atoi(v2.c_str())) return 1;
        else if (atoi(v1.c_str()) < atoi(v2.c_str())) return -1;
        pos1 = idx1+1;
        pos2 = idx2+1;
    }
    
    if (pos1 >= version1.length() && pos2 >= version2.length()) return 0;
    else if (pos1 >= version1.length()) {
        string v2 = version2.substr(pos2, version2.length() - pos2);
        if (atoi(v2.c_str()) == 0) return 0;
        else return -1;
    }
    else {
        string v1 = version1.substr(pos1, version1.length() - pos1);
        if (atoi(v1.c_str()) == 0) return 0;
        else return 1;
    }
}


#endif /* CompareVersion_h */
