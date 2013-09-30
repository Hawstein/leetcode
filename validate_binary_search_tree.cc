#include <iostream>
#include <climits>
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

    bool isValidBST(TreeNode *root){
        return isValidBST1(root);
    }
    bool isValidBST2(TreeNode *root) {
        if(root == NULL) return true;
        if(!root->left && !root->right) return true;
        TreeNode *pre = root->left, *suc = root->right;
        if(pre)
            while(pre->right) pre = pre->right;
        if(suc)
            while(suc->left) suc = suc->left;
        if(root->left && !root->right)
            return pre->val < root->val && isValidBST(root->left);
        if(!root->left && root->right)
            return suc->val > root->val && isValidBST(root->right);

        return pre->val < root->val && suc->val > root->val
            && isValidBST(root->left) && isValidBST(root->right);
    }

    bool isValidBST1(TreeNode *root) {
        return isValidBST1(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST1(TreeNode *node, int lower, int upper){
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;
        
        return isValidBST1(node->left, lower, min(node->val, upper)) && 
               isValidBST1(node->right, max(lower, node->val), upper);
    }    
};

int main(){
    return 0;
}
