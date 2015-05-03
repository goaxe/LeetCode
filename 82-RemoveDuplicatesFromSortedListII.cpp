/*=============================================================================
#     FileName: 82-RemoveDuplicatesFromSortedListII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 12:21:39
#      Version: 0.0.1
#   LastChange: 2015-04-30 12:21:39
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <limits.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    //13ms
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *super_head = new ListNode(INT_MAX),  *prev = super_head, *next = head;
        super_head->next = head;
        while (next) {
            int prev_num = next->val;
            bool has_repeat = false;
            while (next->next != NULL && next->next->val == prev_num) {
                has_repeat = true;
                next = next->next;
            }
            if (!has_repeat) {
                prev = prev->next;
                next = next->next;
            } else {
                prev->next = next->next;
                next->next = NULL;
                next = prev->next;
            }
        }
        return super_head->next;
    }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(1);
    node1->next = node2;
    Solution solution;
    node1 = solution.deleteDuplicates(node1);
    while (node1 != NULL) {
        printf("%d\n", node1->val);
        node1 = node1->next;
    }
    return 0;
}
