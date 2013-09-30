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

    ListNode *swapPairs(ListNode *head){
        return swapPairs1(head);
    }
    ListNode *swapPairs1(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        head = q;
        while(q){
            ListNode *r = q->next;
            q->next = p;
            p->next = r;
            q = NULL;
            if(!r) break;
            if(r->next){
                p->next = r->next;
                p = r;
                q = r->next;
            }
        }
        return head;
    }
    ListNode *swapPairs2(ListNode *head){
        swap(head);
        return head;
    }
    void swap(ListNode* &node){
        if(!node || !node->next) return;
        ListNode *next = node->next;
        ListNode *nextHead = next->next;
        swap(nextHead);
        next->next = node;
        node->next = nextHead;
        node = next;
    }
};

int main(){
    return 0;
}
