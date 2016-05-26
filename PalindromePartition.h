//
//  PalindromePartition.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PalindromePartition_h
#define PalindromePartition_h

#include "DataStructure.h"

using namespace std;

/*********************************** 131 PALINDROME PARTITION **************************************/

string m_s;

vector<string> partitionToSubstrs(vector<int> ss) {
    if (ss.size() == 0) return vector<string>{m_s};
    vector<string> result;
    result.push_back(m_s.substr(0, ss[0]+1));
    for (int i = 1; i < ss.size(); i++) {
        result.push_back(m_s.substr(ss[i-1]+1, ss[i]-ss[i-1]));
    }
    int last = ss[ss.size()-1];
    result.push_back(m_s.substr(last+1, m_s.size() - last - 1));
    return result;
}

void partitionHelper(vector<vector<string>> & result, vector<int> & ss, int level) {
    bool palin = true;
    vector<string> current = partitionToSubstrs(ss);
    for (int i = 0; i < current.size(); i++) {
        palin = isPalindrome(current[i]);
        if (!palin) break;
    }
    if (palin) result.push_back(current);
    
    for (int i = level; i < m_s.size() - 1; i++) {
        ss.push_back(i);
        partitionHelper(result, ss, i+1);
        ss.pop_back();
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    if (s.size() == 0) return result;
    m_s = s;
    vector<int> ss;
    partitionHelper(result, ss, 0);
    
    return result;
}

#endif /* PalindromePartition_h */
