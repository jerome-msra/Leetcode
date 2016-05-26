//
//  OutputHelper.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef OutputHelper_h
#define OutputHelper_h

#include "DataStructure.h"
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename T>
void output2DMatHelper(vector<vector<T>> mat)
{
    if (mat.size() == 0) return;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return;
}

template<typename T>
void output1DVectorHelper(vector<T> vector, string option="horizontal") {
    if (vector.size() == 0) {
        return;
    }
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i];
        if (option == "horizontal") std::cout << " ";
        else std::cout << std::endl;
    }
    std::cout << std::endl;
}

ListNode * convertVectorToList(vector<int> const input) {
    if (input.size() == 0) return nullptr;
    ListNode * head = new ListNode(input[0]);
    ListNode * prev = head;
    for (size_t i = 1; i < input.size(); i++) {
        prev->next = new ListNode(input[i]);
        prev = prev->next;
    }
    
    return head;
}

void outputList(ListNode * head) {
    ListNode * node = head;
    while(node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

#endif /* OutputHelper_h */
