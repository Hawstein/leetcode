#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val){
            ListNode *tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        ListNode *ans = l1, *p = l1;
        l1 = l1->next;
        while(l1 && l2){
            if(l1->val < l2->val){
                l1 = l1->next;
            }
            else{
                ListNode *t = l2;
                l2 = l2->next;
                p->next = t;
                t->next = l1;
            }
            p = p->next;
        }
        if(!l1) p->next = l2;
        return ans;
    }
};

int main(){
    return 0;
}
