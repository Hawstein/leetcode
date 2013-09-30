#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
        TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    };

    void connect(TreeLinkNode *root){
        connect1(root);
    }
    void connect2(TreeLinkNode *root) {
        if(root == NULL) return;
        queue<TreeLinkNode*> que[2];
        int cur = 0;
        que[cur].push(root);
        while(!que[cur].empty()){
            TreeLinkNode *q = que[cur].front();
            que[cur].pop();
            if(q->left) que[1-cur].push(q->left);
            if(q->right) que[1-cur].push(q->right);
            while(!que[cur].empty()){
                TreeLinkNode *p = q;
                q = que[cur].front();
                que[cur].pop();
                if(q->left) que[1-cur].push(q->left);
                if(q->right) que[1-cur].push(q->right);
                p->next = q;
            }
            cur = 1 - cur;
        }
    }
    void connect1(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        TreeLinkNode *parent = root;
        while (parent->left)
        {
            TreeLinkNode *pHead = parent;
            pHead->left->next = pHead->right;
            TreeLinkNode *cTail = pHead->right;
            while (pHead = pHead->next)
            {
                cTail->next = pHead->left;
                pHead->left->next = pHead->right;
                cTail = pHead->right;
            }
            cTail->next = NULL;
            parent = parent->left;
        }
    }
};

int main(){
    return 0;
}
