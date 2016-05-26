//
//  AlienOrder.h
//  LeetCode
//
//  Created by Jerome on 5/25/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef AlienOrder_h
#define AlienOrder_h

bool dfsHelper(list<char> & listresult, unordered_set<char> & path, vector<unordered_set<char>> & graph, char node, unordered_set<char> & all) {
    all.erase(node);
    path.insert(node);
    for (auto next : graph[node-'a']) {
        if (path.count(next)>0) return false;
        if (all.count(next)>0) {
            bool cylic = dfsHelper(listresult, path, graph, next, all);
            if (!cylic) return false;
        }
    }
    listresult.insert(listresult.begin(), node);
    return true;
}

string alienOrder(vector<string>& words) {

    unordered_set<char> all;
    vector<unordered_set<char>> graph(26);
    for (int i = 0; i < words.size(); i++) {
        for (auto c : words[i]) {
            all.insert(c);
        }
    }
    
    for (int i = 0; i < words.size()-1; i++) {
        string prev = words[i];
        string next = words[i+1];
        int pos = 0;
        while(pos < min(prev.length(), next.length()) && prev[pos]==next[pos]) {
            pos++;
        }
        if (pos < min(prev.length(), next.length())) {
            graph[prev[pos]-'a'].insert(next[pos]);
        }
    }
    
    list<char> listresult;
    for (int i = 0; i < 26; i++) {
        if (graph[i].size()>0 && all.count(i+'a')>0) {
            unordered_set<char> path;
            bool cycle = dfsHelper(listresult, path, graph, i+'a', all);
            if (!cycle) return "";
        }
    }
    
    if (all.size()>0) {
        listresult.insert(listresult.end(), all.begin(), all.end());
    }
    string result;
    for (auto c : listresult) {
        result.push_back(c);
    }
    
    return result;
}



#endif /* AlienOrder_h */
