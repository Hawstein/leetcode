#include <iostream>
#include <map>
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
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    int maxPathSum(TreeNode *root){
        return maxPathSum1(root);
    }
    // TLE for large
    int maxPathSum1(TreeNode *root) {
        if(root == NULL) return -2000000000;
        return max(max(maxPathSum1(root->left), maxPathSum1(root->right)),
                   max(maxPathSumPart(root->left),0)+max(maxPathSumPart(root->right),0)+root->val);
    }
    int maxPathSumPart(TreeNode *root){
        if(root == NULL) return 0;
        return max(maxPathSumPart(root->left), maxPathSumPart(root->right)) + root->val;
    }
    int maxPathSum2(TreeNode *root){
        int ans = -2000000000;
        if(root == NULL) return 0;
        maxPathSumRe(root, ans);
        return ans;
    }
    int maxPathSumRe(TreeNode *root, int &ans){
        if(root == NULL) return 0;
        int l = maxPathSumRe(root->left, ans);
        int r = maxPathSumRe(root->right, ans);
        ans = max(ans, root->val);
        ans = max(ans, l + r + root->val);
        ans = max(ans, max(l, r) + root->val);
        return max(root->val, max(l, r)+root->val);
    }
    
};

int main(){
    return 0;
}
