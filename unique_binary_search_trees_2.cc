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
         
    vector<TreeNode *> generateTrees(int n) {
        return _generateTrees(1, n);
    }
    vector<TreeNode*> _generateTrees(int begin, int end){
        vector<TreeNode*> ans;
        if(begin > end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=begin; i<=end; ++i){
            vector<TreeNode*> left = _generateTrees(begin, i-1);
            vector<TreeNode*> right = _generateTrees(i+1, end);
            for(int j=0; j<left.size(); ++j)
                for(int k=0; k<right.size(); ++k){
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
        }
        return ans;
    }
};

int main(){
    return 0;
}
