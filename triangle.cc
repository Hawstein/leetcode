#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if(n < 1) return -1;
        int d[n];
        for(int i=0; i<n; ++i)
            d[i] = triangle[n-1][i];
        for(int i=n-2; i>=0; --i)
            for(int j=0; j<=i; ++j)
                d[j] = min(d[j], d[j+1]) + triangle[i][j];
        return d[0];
    }
};

int main(){
    return 0;
}
