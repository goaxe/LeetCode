/*=============================================================================
#     FileName: 60-PermutationSequence.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-11 20:18:53
#      Version: 0.0.1
#   LastChange: 2015-04-11 20:18:54
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //4ms
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int pCount = 1;
        for(int i = 0 ; i < n; ++i) {
            nums[i] = i + 1;
            pCount *= (i + 1);
        }

        k--;
        string res = "";
        for(int i = 0 ; i < n; i++) {
            pCount = pCount/(n-i);
            int selected = k / pCount;
            res += ('0' + nums[selected]);
            
            for(int j = selected; j < n-i-1; j++)
                nums[j] = nums[j+1];
            k = k % pCount;
            for (int k = 0; k <n; k ++) {
                cout << nums[k] << " ";
            }
            cout << endl;
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.getPermutation(4, 3) << endl; 
    return 0;
}
