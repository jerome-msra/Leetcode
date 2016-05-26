//
//  TextJustification.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef TextJustification_h
#define TextJustification_h

#include "DataStructure.h"

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0;
    while(i < words.size()) {
        vector<string> current;
        int len = words[i].length();
        current.push_back(words[i]);
        i++;
        while(true) {
            if (i < words.size() && len +1 +words[i].length() < maxWidth) {
                len += 1+words[i].length();
                current.push_back(words[i]);
                i++;
            }
            else {
                break;
            }
        }
        int lenSpace = maxWidth - len + (current.size()-1);
        int indiSpace;
        if (current.size()>1) indiSpace = lenSpace / (current.size()-1);
        else indiSpace = lenSpace;
        int firstSpace = indiSpace;
        if (current.size()>1 && indiSpace*(current.size()-1) < lenSpace) {
            firstSpace += lenSpace - indiSpace*(current.size()-1);
        }
        int finalSpace = 0;
        if (i>=words.size()) {
            finalSpace = maxWidth - len;
        }
        string currStr;
        for (int s = 0; s < current.size(); s++) {
            int numSpace = (s==0 ? firstSpace : indiSpace);
            currStr += current[s];
            if (s!=current.size()-1) {
                for (int k = 0; k < numSpace; k++) currStr += " ";
            }
            else {
                if (finalSpace > 0)
                    for (int k = 0; k < finalSpace; k++) currStr += " ";
                else
                    for (int k = 0; k < numSpace; k++) currStr += " ";
            }
        }
        std::cout << currStr << std::endl;
        result.push_back(currStr);
    }
    return result;
}


#endif /* TextJustification_h */
