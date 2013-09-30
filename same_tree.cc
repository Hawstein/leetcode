#include <iostream>
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
    
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        else if(p && q){
            if(p->val == q->val)
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            else
                return false;
        }
        else return false;
    }
};

int main(){
    return 0;
}
