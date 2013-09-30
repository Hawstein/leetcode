#include <iostream>
#include <vector>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> elem;
        _pathSum(root, sum, ans, elem);
        return ans;
    }
    void _pathSum(TreeNode *root, int sum, vector<vector<int> > &ans, vector<int> elem){
        if(root == NULL) return;
        elem.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == root->val)
                ans.push_back(elem);
        }
        else{
            _pathSum(root->left, sum-root->val, ans, elem);
            _pathSum(root->right, sum-root->val, ans, elem);
        }
    }
};

int main(){
    return 0;
}
