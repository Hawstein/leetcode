#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        return _numTrees(1, n);
    }
    // recursion
    int _numTrees(int begin, int end){
        int sum = 0;
        for(int i=begin; i<=end; ++i){
            int left = _numTrees(begin, i-1);
            int right = _numTrees(i+1, end);
            left = left==0 ? 1 : left;
            right = right==0 ? 1 : right;
            sum += left * right;
        }
        return sum;
    }
    // dp 1
    int numTrees_dp(int n){
        int sum = 0;
        int d[n+2][n+2];
        for(int i=1; i<n+2; ++i)
            d[i][i-1] = 1;
        for(int cnt=1; cnt<=n; ++cnt){
            for(int i=1,j=cnt; j<=n; ++i,++j){
                d[i][j] = 0;
                for(int k=i; k<=j; ++k){
                    d[i][j] += d[i][k-1] * d[k+1][j];
                }
            }
        }
        return d[1][n];
    }
    // dp 2
    int numTrees_dp2(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
};

int main(){
    Solution sln;
    cout<<sln.numTrees(3)<<endl;
    cout<<sln.numTrees_dp(3)<<endl;
    cout<<sln.numTrees_dp2(3)<<endl;
    return 0;
}
