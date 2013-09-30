#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int d[m][n];
        for(int i=0; i<m; ++i)
            d[i][0] = 1;
        for(int j=0; j<n; ++j)
            d[0][j] = 1;

        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                d[i][j] = d[i-1][j] + d[i][j-1];

        return d[m-1][n-1];
    }
    int uniquePaths1(int m, int n){
        int d[n];
        for(int j=0; j<n; ++j)
            d[j] = 1;

        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                d[j] = d[j-1] + d[j];
        return d[n-1];
    }
    // TLE
    int uniquePaths2(int m, int n){
        if(m==1 || n==1)
            return 1;
        else
            return uniquePaths2(m-1, n) + uniquePaths2(m, n-1);
    }
};

int main(){
    Solution sln;
    cout<<sln.uniquePaths(3, 5)<<endl;
    cout<<sln.uniquePaths1(3, 5)<<endl;
    cout<<sln.uniquePaths2(3, 5)<<endl;
    return 0;
}
