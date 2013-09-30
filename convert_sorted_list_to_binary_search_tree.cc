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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    TreeNode *sortedListToBST(ListNode *head){
        int n = 0;
        ListNode *p = head;
        for(; p; p=p->next, ++n);
        return _sortedListToBST(head, n);
    }
    TreeNode* _sortedListToBST(ListNode* head, int n){
        if(head == NULL || n==0) return NULL;
        ListNode *t = head;
        for(int i=0; i<n/2; ++i)
            t = t->next;
        TreeNode *root = new TreeNode(t->val);
        root->left = _sortedListToBST(head, n/2);
        root->right = _sortedListToBST(t->next, n-n/2-1);

        return root;
    }
};

int main(){
    return 0;
}
