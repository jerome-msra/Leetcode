//
//  TreeCodec.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef TreeCodec_h
#define TreeCodec_h

#include "DataStructure.h"

using namespace std;

/************************************* Tree Codec *************************************/

class tokenizer {
public:
    tokenizer(string s) {m_s = s; pos = 0;};
    string nextToken() {
        while(pos < m_s.size() && m_s[pos]==' ') pos++;
        if (pos == m_s.size()) return "";
        int startpos = pos;
        while(pos < m_s.size() && m_s[pos]!=' ') pos++;
        return m_s.substr(startpos, pos-startpos);
    }
    
    int pos;
    string m_s;
};

class TreeCodec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        string result;
        while(!myqueue.empty()) {
            size_t n = myqueue.size();
            for (int i = 0; i < n; i++) {
                TreeNode * node = myqueue.front();
                myqueue.pop();
                if (node==nullptr) {
                    result += "null ";
                }
                else {
                    result += to_string(node->val) + " ";
                    myqueue.push(node->left);
                    myqueue.push(node->right);
                }
            }
        }
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root = nullptr;
        tokenizer * mytoken = new tokenizer(data);
        string tok = mytoken->nextToken();
        if (tok.length() == 0) return root;
        root = new TreeNode(atoi(tok.c_str()));
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty()) {
            for (int i = 0; i < myqueue.size(); i++) {
                TreeNode * node = myqueue.front();
                myqueue.pop();
                if (node==nullptr) continue;
                string tok = mytoken->nextToken();
                if (tok.length()>0 && tok != "null") node->left = new TreeNode(atoi(tok.c_str()));
                else node->left = nullptr;
                tok = mytoken->nextToken();
                if (tok.length()>0 && tok != "null") node->right = new TreeNode(atoi(tok.c_str()));
                else node->right = nullptr;
                myqueue.push(node->left);
                myqueue.push(node->right);
            }
        }
        return root;
    }
};

#endif /* TreeCodec_h */
