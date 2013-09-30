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
    
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        return _minDepth(root);
    }
    int _minDepth(TreeNode *root){
        if(!root->left && !root->right) return 1;
        else if(root->left && !root->right) return _minDepth(root->left)+1;
        else if(!root->left && root->right) return _minDepth(root->right)+1;
        else return min(_minDepth(root->left), _minDepth(root->right)) + 1;
    }
};

int main(){
    return 0;
}
