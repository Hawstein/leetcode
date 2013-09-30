#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        for(int i=0; i<n; ++i) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(!st.empty()) {
                s[st.top()] = '*';
                s[i] = '*';
                st.pop();
            }
        }
        int maxlen = 0, len = 0;
        for(int i=0; i<n; ++i) {
            if(s[i] == '*') {
                ++len;
            }
            else {
                maxlen = max(maxlen, len);
                len = 0;
            }
        }
        maxlen = max(maxlen, len);
        return maxlen;
    }
    
    int longestValidParentheses1(string s) {
        stack<int> stk;
        int res = 0, count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(count);
                count = 0;
            } else if (!stk.empty()) {
                count += (1 + stk.top());
                stk.pop();
                res = max(res, count);
            } else {
                count = 0;
            }
        }
        return res * 2;
    }
};

int main() {
    Solution sln;
    cout<<sln.longestValidParentheses(")(()())(()");
    return 0;
}
