#include <iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T){
        return numDistinct1(S, T);
    }
    int numDistinct1(string S, string T){
        int m = S.length(), n = T.length();
        int d[m+1][n+1];
        for(int i=0; i<=m; ++i)
            d[i][0] = 1;
        for(int j=1; j<=n; ++j)
            d[0][j] = 0;
        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j)
                if(S[i-1] == T[j-1])
                    d[i][j] = d[i-1][j] + d[i-1][j-1];
                else
                    d[i][j] = d[i-1][j];
        return d[m][n];
    }
    int numDistinct2(string S, string T){
        int m = S.length(), n = T.length();
        int d[n+1];
        d[0] = 1;
        for(int j=1; j<=n; ++j)
            d[j] = 0;
        for(int i=1; i<=m; ++i)
            for(int j=n; j>0; --j)
                if(S[i-1] == T[j-1])
                    d[j] = d[j] + d[j-1];
        return d[n];
    }
};

int main(){
    return 0;
}
