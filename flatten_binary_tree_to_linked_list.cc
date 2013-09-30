#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        TreeNode *cur = root, *p, *q;
        stack<TreeNode*> st;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else if(!st.empty()){
                q = p = st.top();
                st.pop();
                while(!p->right && !st.empty()){
                    p = st.top();
                    st.pop();
                }
                if(p->right){
                    q->left = p->right;
                    cur = q->left;
                }
            }
        }
        p = root;
        q = p->left;
        while(q){
            p->right = q;
            p->left = NULL;//set left child NULL
            p = q;
            q = p->left;
        }
    }
};

int main(){
    return 0;
}
