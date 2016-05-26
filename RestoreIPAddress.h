//
//  RestoreIPAddress.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RestoreIPAddress_h
#define RestoreIPAddress_h

#include "DataStructure.h"

using namespace std;

/*********************************** 93 RESTORE IP ADDRESS **************************************/

string m_s;
void dfsIp(vector<string> & result, vector<int> & commapos, int level) {
    if (commapos.size() == 3) {
        string subs = m_s.substr(commapos[2]);
        if (subs.length() == 1 || (atoi(subs.c_str()) <= 255 && subs[0] != '0')) {
            string res;
            res += m_s.substr(0, commapos[0]);
            res.push_back('.');
            res += m_s.substr(commapos[0], commapos[1]-commapos[0]);
            res.push_back('.');
            res += m_s.substr(commapos[1], commapos[2]-commapos[1]);
            res.push_back('.');
            res += m_s.substr(commapos[2]);
            result.push_back(res);
        }
        return;
    }
    
    for (int i = level; i < min((size_t)level+3, m_s.length()); i++) {
        string subs = m_s.substr(level-1, i-level+1);
        if (subs.length() == 1 || (atoi(subs.c_str()) <= 255 && subs[0] != '0')){
            commapos.push_back(i);
            dfsIp(result, commapos, i+1);
            commapos.pop_back();
        }
    }
    
    return;
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.length() == 0) return result;
    m_s = s;
    vector<int> commapos;
    dfsIp(result, commapos, 1);
    return result;
}

#endif /* RestoreIPAddress_h */
