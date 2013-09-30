#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    void fromPtoQ(queue<TreeNode*> &p, queue<TreeNode*> &q, vector<vector<int> > &ans) {
        vector<int> elem;
        while(!p.empty()) {
            TreeNode* n = p.front();
            p.pop();
            elem.push_back(n->val);
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        if(!elem.empty()) ans.push_back(elem);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if(!root) return ans;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            fromPtoQ(q1, q2, ans);
            fromPtoQ(q2, q1, ans);
        }
        // reverse
        for(int i=0; i<ans.size()/2; ++i) {
            vector<int> tmp = ans[i];
            ans[i] = ans[ans.size()-1-i];
            ans[ans.size()-1-i] = tmp;
        }
        return ans;
    }
    
};

int main() {
    return 0;
}
