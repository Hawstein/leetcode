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
    
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *p = head, *q = head->next;
        while(q){
            if(q->val != p->val){
                p = p->next;
                p->val = q->val;
            }
            q = q->next;
        }
        for(ListNode *t = p->next; t; ){
            q = t;
            t = t->next;
            delete q;
        }
        p->next = NULL;
        return head;
    }
};

int main(){
    return 0;
}
