//
//  StringCodec.h
//  LeetCode
//
//  Created by Jerome on 5/22/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef StringCodec_h
#define StringCodec_h

#include "DataStructure.h"

using namespace std;

class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for (auto s : strs) {
            int x = 0;
            for (int c = 0; c < s.length(); c++) {
                int r = c%4;
                x = x << 8;
                x = x | s[c];
                if (r==3) {
                    result += "4 " + to_string(x) + " ";
                    x = 0;
                }
                if (c==s.length()-1 && r!=3) {
                    result += to_string(r+1) + " " + to_string(x);
                }
            }
            result.push_back('\n');
        }
        return result;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int p = 0;
        vector<string> result;
        while(p < s.length()) {
            int ppos = p;
            while(p<s.length() && s[p]!='\n') p++;
            string single = s.substr(ppos, p-ppos);
            string recover = "";
            int sp = 0;
            while(sp < single.length()) {
                int num = single[sp]-'0';
                sp+=2;
                int sppos = sp;
                while(sp < single.length() && single[sp]!=' ') sp++;
                int x = stoi(single.substr(sppos, sp-sppos));
                string temp;
                for (int i = 0; i < num; i++) {
                    char c = x & 0xFF;
                    temp.push_back(c);
                    x = x >> 8;
                }
                reverse(temp.begin(), temp.end());
                recover += temp;
                sp++;
            }
            result.push_back(recover);
            p++;
        }
        
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

#endif /* StringCodec_h */
