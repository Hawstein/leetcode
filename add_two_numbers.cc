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

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(0);
        ListNode *p = ans;
        int c = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + c;
            ListNode *q = new ListNode(sum%10);
            p->next = q;
            p = q;
            c = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + c;
            ListNode *q = new ListNode(sum%10);
            p->next = q;
            p = q;
            c = sum / 10;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + c;
            ListNode *q = new ListNode(sum%10);
            p->next = q;
            p = q;
            c = sum / 10;
            l2 = l2->next;
        }
        if(c){
            ListNode *q = new ListNode(1);
            p->next = q;
        }
        p = ans;
        ans = ans->next;
        delete p;
        return ans;
    }
};

int main(){
    return 0;
}
