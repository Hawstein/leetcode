#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        return _buildTree(preorder.begin(), inorder.begin(), n);
    }
    TreeNode* _buildTree(vector<int>::iterator preorder, vector<int>::iterator inorder, int n){
        if(n <= 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder+n, *preorder);
        int pos = it - inorder;
        TreeNode* root = new TreeNode(*preorder);
        root->left = _buildTree(preorder+1, inorder, pos);
        root->right = _buildTree(preorder+pos+1, inorder+pos+1, n-pos-1);
        return root;
    }
};

int main(){
    return 0;
}
