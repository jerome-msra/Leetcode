//
//  CopyListWithRandomPointer.h
//  LeetCode
//
//  Created by Jerome on 6/8/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CopyListWithRandomPointer_h
#define CopyListWithRandomPointer_h

#include "DataStructure.h"

using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<RandomListNode*, RandomListNode*> nodeMap;
    RandomListNode * dummy = new RandomListNode(0);
    RandomListNode * node = head;
    RandomListNode * prev = dummy;
    nodeMap[nullptr] = nullptr;
    while(node!=nullptr) {
        RandomListNode * newnode = new RandomListNode(node->label);
        nodeMap[node] = newnode;
        prev->next = newnode;
        prev = newnode;
        node = node->next;
    }
    node = head;
    while(node!=nullptr) {
        RandomListNode * newnode = nodeMap[node];
        RandomListNode * randnode = nodeMap[node->random];
        newnode->random = randnode;
        node = node->next;
    }
    
    return dummy->next;
}

#endif /* CopyListWithRandomPointer_h */
