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
class Solution{
public:
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    TreeNode *sortedArrayToBST(vector<int> &num){
        TreeNode *root = NULL;
        _sortedArrayToBST(root, num, 0, num.size()-1);
        return root;
    }
    void _sortedArrayToBST(TreeNode* &root, vector<int> &num, int low, int high){
        if(low <= high){
            int mid = low + (high-low)/2;
            root = new TreeNode(num[mid]);
            _sortedArrayToBST(root->left, num, low, mid-1);
            _sortedArrayToBST(root->right, num, mid+1, high);
        }
    }
};

int main(){
    return 0;
}
