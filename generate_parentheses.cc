#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        _generateParenthesis(ans, "", 0, 0, n);
        return ans;
    }
    void _generateParenthesis(vector<string> &ans, string s, int left, int right, int n){
        if(left==n && right==n){
            ans.push_back(s);
            return;
        }
        if(left < n)
            _generateParenthesis(ans, s+'(', left+1, right, n);
        if(right < left)
            _generateParenthesis(ans, s+')', left, right+1, n);
    }
};

int main(){
    return 0;
}
