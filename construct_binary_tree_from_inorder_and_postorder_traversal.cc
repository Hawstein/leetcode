#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || postorder.empty())
            return NULL;
        int m = inorder.size();
        int n = postorder.size();
        TreeNode *root = new TreeNode(postorder[n-1]);
        int mid = 0;
        while(inorder[mid] != postorder[n-1]) ++mid;
        int e2 = -1;
        for(int i=0; i<mid; ++i, ++e2);
        root->left = _buildTree(inorder, 0, mid-1, postorder, 0, e2);
        root->right = _buildTree(inorder, mid+1, m-1, postorder, e2+1, n-2);
        return root;
    }
    TreeNode* _buildTree(vector<int> &inorder, int b1, int e1, vector<int> &postorder, int b2, int e2){
        if(b1 > e1 || b2 > e2) return NULL;
        TreeNode *root = new TreeNode(postorder[e2]);
        int mid = b1;
        while(inorder[mid] != postorder[e2]) ++mid;
        int end = b2-1;
        for(int i=b1; i<mid; ++i, ++end);
        root->left = _buildTree(inorder, b1, mid-1, postorder, b2, end);
        root->right = _buildTree(inorder, mid+1, e1, postorder, end+1, e2-1);
        return root;
    }

    // simple version
    TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        return buildTreeRe(inorder.begin(), postorder.begin(), n);
    }

    TreeNode *buildTreeRe(vector<int>::iterator inorder, vector<int>::iterator postorder, int n) {
        if (n <= 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder+n, *(postorder+n-1));
        int pos = it - inorder;
        TreeNode *root = new TreeNode(*(postorder+n-1));
        root->left = buildTreeRe(inorder, postorder, pos);
        root->right = buildTreeRe(inorder+pos+1, postorder+pos, n-pos-1);
        return root;
    }
 
};

int main(){
    return 0;
}
