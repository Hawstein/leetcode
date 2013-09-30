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
        if(head == NULL) return NULL;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *r = start;
        ListNode *p = r->next, *q = p->next;
        while(p && q){
            if(p->val == q->val){
                while(p && p->val == q->val){
                    p = p->next;
                }
                r->next = p;
            }
            else{
                r = p;
                p = r->next;
            }
            if(!p) break;
            q = p->next;
        }
        return start->next;
    }
};

int main(){
    return 0;
}
