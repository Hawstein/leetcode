#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length(), n=s2.length(), k=s3.length();
        if(m+n != k) return false;
        if(k == 0) return true;
        int d[m+1][n+1];
        d[0][0] = true;
        for(int i=1; i<=m; ++i)
            d[i][0] = s1[i-1]==s3[i-1];
        for(int j=1; j<=n; ++j)
            d[0][j] = s2[j-1]==s3[j-1];

        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j)
                d[i][j] = (d[i-1][j] && s1[i-1]==s3[i+j-1]) ||
                    (d[i][j-1] && s2[j-1]==s3[i+j-1]);

        return d[m][n];
    }
};

int main(){
    Solution sln;
    string s1 = "aa";
    string s2 = "aeb";
    string s3 = "aabae";
    cout<<sln.isInterleave(s1,s2,s3)<<endl;
    return 0;
}
