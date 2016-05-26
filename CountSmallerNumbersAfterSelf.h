//
//  CountSmallerNumbersAfterSelf.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CountSmallerNumbersAfterSelf_h
#define CountSmallerNumbersAfterSelf_h

#include "DataStructure.h"

using namespace std;

/************************** 315. Count of Smaller Numbers After Self **************************/

vector<int> bit;
int bit_last(int i){
    return i&-i;
}

void bit_add(int i, int val){
    i++;
    while(i<bit.size()){
        bit[i]+=val;
        i=i+bit_last(i);
    }
}

int bit_sum(int i){
    i++;
    int sum=0;
    while(i>0){
        sum+=bit[i];
        i=i-bit_last(i);
    }
    return sum;
}

vector<int> countSmaller(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    bit.resize(nums.size()+1, 0);
    
    //get the ordered-index-array
    vector<int> sorted_nums(nums);
    unordered_map<int, int> dict;
    sort(sorted_nums.begin(), sorted_nums.end());
    
    for(int i=0; i<nums.size(); i++){
        dict[sorted_nums[i]] = i+1;
    }
    
    for(int i=nums.size()-1; i>=0; i--){
        //count the smaller numbers less than nums[i] , so use bit_sum(dict[nums[i]-1)
        result[i]=bit_sum(dict[nums[i]]-1);
        bit_add(dict[nums[i]], 1);
    }
    return result;
}

#endif /* CountSmallerNumbersAfterSelf_h */
