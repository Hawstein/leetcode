#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> getPermutation1(string s, int len, int &k, string &ans) {
        vector<string> res;
        for(int i=0; i<s.length(); ++i) {
            string t = s;
            char v = t[i];
            t.erase(t.begin()+i);
            vector<string> part_ans = getPermutation1(t, len, k, ans);
            if(part_ans.empty()) {
                string tt(1, v);
                res.push_back(tt);
                if(s.length() == len) --k;
                if(k == 0) {
                    ans = tt;
                    return res;
                }
            }
            else {
                for(int j=0; j<part_ans.size(); ++j) {
                    res.push_back(v + part_ans[j]);
                    if(s.length() == len) --k;
                    if(k == 0) {
                        ans = v + part_ans[j];
                        return res;
                    }
                }
            }
        }
        return res;
    }
    string getPermutation1(int n, int k) {
        if(n < 1 || n > 9) return "";
        string str = "";
        for(int i=0; i<n; ++i)
            str += '1' + i;
        string ans = "";
        getPermutation1(str, n, k, ans);
        return ans;
    }
    int fact(int n) {
        if(n==0 || n==1) return 1;
        return n * fact(n-1);
    }
    string getPermutation(string s, int n, int k) {
        if(n == 0) return "";
        int f = fact(n-1);
        int v = (k-1) / f;
        char c = s[v];
        k -= v * f;
        s.erase(s.begin() + v);
        string re = getPermutation(s, n-1, k);
        return c + re;
    }
    string getPermutation(int n, int k) {
        if(n < 1 || n > 9) return "";
        string str = "";
        for(int i=0; i<n; ++i)
            str += '1' + i;
        return getPermutation(str, n, k);
    }
};

int main() {
    Solution sln;
    for(int i=1; i<7; ++i)
        cout<<sln.getPermutation(3, i)<<endl;;
    return 0;
}
