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
    
    int sumNumbers(TreeNode *root) {
        int sum = 0, num = 0;
        _sumNumbers(root, sum, num);
        return sum;
    }
    void _sumNumbers(TreeNode *root, int &sum, int num){
        if(root == NULL) return;
        num = num * 10 + root->val;
        if(!root->left && !root->right){
            sum += num;
        }
        else{
            _sumNumbers(root->left, sum, num);
            _sumNumbers(root->right, sum, num);
        }
    }
};

int main(){
    return 0;
}
