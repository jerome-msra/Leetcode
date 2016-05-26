//
//  PathToSum.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PathToSum_h
#define PathToSum_h

#include "DataStructure.h"

using namespace std;

/****************************************** PATH TO SUM ******************************************/

void generatePath(vector<string> & paths, string & curr, TreeNode * node)
{
    if (node == nullptr) return;
    
    curr.push_back(node->val + '0');
    
    if (node->left == nullptr && node->right == nullptr)
    {
        paths.push_back(curr);
        return;
    }
    
    if (node->left) { generatePath(paths, curr, node->left);
        curr.pop_back(); }
    if (node->right) { generatePath(paths, curr, node->right);
        curr.pop_back(); }
    
    return;
}

int pathToSum(vector<string> & paths)
{
    int sum = 0;
    for (int s = 0; s < paths.size(); s++)
    {
        int csum = 0;
        string cs = paths[s];
        for (int j = 0; j < cs.length(); j++)
        {
            csum = csum * 10 + (cs[j] - '0');
        }
        sum += csum;
    }
    
    return sum;
}

int sumNumbers(TreeNode* root) {
    vector<string> paths;
    if (root == nullptr) return 0;
    string curr;
    generatePath(paths, curr, root);
    
    return pathToSum(paths);
}


#endif /* PathToSum_h */
