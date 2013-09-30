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

    void swap(ListNode* &p, ListNode* &q) {
        ListNode *t = p;
        p = q;
        q = t;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pbegin = dummy;
        for(int i=1; i<m; pbegin=pbegin->next, ++i);
        ListNode *qbegin = pbegin->next;
        ListNode *p=qbegin, *q=NULL;
        for(; swap(q, p), m<=n; swap(q->next, p), ++m);
        pbegin->next = p;
        qbegin->next = q;
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    return 0;
}
