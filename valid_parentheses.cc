#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> st;
        for(int i=0; i<len; ++i) {
            char c = s[i];
            if(c=='(' || c=='[' || c=='{') {
                st.push(c);
            }
            else {
                if(st.empty()) return false;
                char left = st.top();
                st.pop();
                if((left=='(' && c==')') || (left=='[' && c==']') || (left=='{' && c=='}'))
                    continue;
                else
                    return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};

int main() {
    return 0;
}
