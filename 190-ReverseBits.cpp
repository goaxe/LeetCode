/*=============================================================================
#     FileName: 190-ReverseBits.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-17 21:34:49
#      Version: 0.0.1
#   LastChange: 2015-06-17 21:34:49
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //4ms
    uint32_t reverseBits(uint32_t n) {
        int len = 32;
        vector<int> flag(len);
        for (int i = 0; i < len; i ++) {
            flag[i] = (n & (1 << i)) >> i;
        }
        uint32_t result = 0;
        for (int i = 0; i < len; i ++) {
            if (flag[i]) {
                result |= (1 << (len - i - 1));
            }
        }
        return result;
    }
};
