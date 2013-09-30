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
    
    bool hasPathSum(TreeNode *root, int sum) {
        
    }
    bool hasPathSum2(TreeNode *root, int sum){
        if(root == NULL) return false;
        if(!root->left && !root->right)
            return sum==root->val;
        return hasPathSum2(root->left, sum-root->val) ||
            hasPathSum2(root->right, sum-root->val);
    }
    bool hasPathSum1(TreeNode *root, int sum){
        if(root == NULL) return false;
        return _hasPathSum(root, sum);
    }
    bool _hasPathSum(TreeNode *root, int sum){
        sum -= root->val;
        if(!root->left && !root->right){
            if(sum == 0) return true;
            else return false;
        }
        else{
            bool lb = false, rb = false;
            if(root->left)
                lb = _hasPathSum(root->left, sum);
            if(root->right)
                rb = _hasPathSum(root->right, sum);
            return lb || rb;
        }
    }
};

int main(){
    return 0;
}
