// 状态：
// d(i)表示s[0..i]划为回文串的最小划分数，d(len-1)为所求
// 状态转移方程：
// d(0)即s[0..0]的划分数为0，因为一个字符本身就是回文
// 如果s[0..i]为回文串，则d(i)=0，continue
// 否则d(i)=min(d(j-1)+1)，其中s[j..i]是回文串
#include <iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool isP[n][n];
        for(int i=0; i<n; ++i)
            isP[i][i] = true;
        for(int i=n-2; i>=0; --i)
            for(int j=i+1; j<n; ++j) {
                if(s[i] == s[j])
                    isP[i][j] = i+1 < j ? isP[i+1][j-1] : true;
                else
                    isP[i][j] = false;
            }
        int d[n];
        d[0] = 0;
        for(int i=1; i<n; ++i) {
            if(isP[0][i]) {
                d[i] = 0;
                continue;
            }
            d[i] = d[i-1] + 1;
            for(int j=1; j<i; ++j) {
                if(isP[j][i])
                    d[i] = min(d[i], d[j-1]+1);
            }
        }
        return d[n-1];
    }
};

int main() {
    Solution sln;
    cout<<sln.minCut("abcded");
    return 0;
}
