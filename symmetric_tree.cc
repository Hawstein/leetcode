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
    
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return _isSymmetric(root->left, root->right);
    }
    bool _isSymmetric(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if((!left && right) || (left && !right)) return false;
        if(left->val != right->val) return false;

        return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
    }
};

int main(){
    return 0;
}
