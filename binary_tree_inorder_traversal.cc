#include <iostream>
#include <stack>
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
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> ans;
        inorderTraversal1(root, ans);
        return ans;
    }
    void inorderTraversal1(TreeNode *root, vector<int> &ans){
        if(root == NULL) return;
        inorderTraversal1(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal1(root->right, ans);
    }
    void inorderTraversal2(TreeNode *root, vector<int> &ans){
        stack<TreeNode*> st;
        if(root == NULL) return;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            while(root->left){
                st.push(root);
                root = root->left;
            }
            ans.push_back(root->val);
            while(!st.empty() && root->right == NULL){
                root = st.top();
                st.pop();
                ans.push_back(root->val);
            }
            if(root->right) st.push(root->right);
        }
    }
    void inorderTraversal3(TreeNode *root, vector<int> &ans){
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else if(!st.empty()){
                ans.push_back(st.top()->val);
                cur = st.top()->right;
                st.pop();
            }
        }
    }
};

int main(){
    return 0;
}
