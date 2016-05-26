//
//  ReverseWordsInString.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ReverseWordsInString_h
#define ReverseWordsInString_h

#include "DataStructure.h"

using namespace std;

/**************************** 151. Reverse Words in a String ******************************/

void reverseWords(string &s) {
    if (s.length() == 0) return;
    vector<string> words;
    int i = 0;
    while(i < s.length()) {
        while(i<s.length() && s[i]==' ') i++;
        int startpos = i;
        while(i<s.length() && s[i]!=' ') i++;
        if (i >= s.length() && startpos >= s.length()) break;
        words.push_back(s.substr(startpos,i-startpos));
        i++;
    }
    
    reverse(words.begin(), words.end());
    stringstream iss;
    for (int i = 0; i < words.size(); i++) {
        iss << words[i];
        if (i != words.size()-1) iss << " ";
    }
    s = iss.str();
}

#endif /* ReverseWordsInString_h */
