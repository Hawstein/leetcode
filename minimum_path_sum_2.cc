#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty()) return -1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int d[m][n];
        memset(d, 0, sizeof(d));
        for(int i=0; i<m; ++i){
            if(obstacleGrid[i][0] == 0)
                d[i][0] = 1;
            else
                break;
        }
        for(int j=0; j<n; ++j){
            if(obstacleGrid[0][j] == 0)
                d[0][j] = 1;
            else
                break;
        }

        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                if(obstacleGrid[i][j] == 1)
                    d[i][j] = 0;
                else
                    d[i][j] = d[i-1][j] + d[i][j-1];

        return d[m-1][n-1];
    }
    int uniquePathsWithObstacles1(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty()) return -1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int d[n];
        memset(d, 0, sizeof(d));
        for(int j=0; j<n; ++j)
            if(obstacleGrid[0][j] == 0)
                d[j] = 1;
            else
                break;
        bool obstacle = obstacleGrid[0][0] ? true : false;
        for(int i=1; i<m; ++i){
            d[0] = 0;
            if(!obstacle && obstacleGrid[i][0]==0)
                d[0] = 1;
            else
                obstacle = true;
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j] == 1)
                    d[j] = 0;
                else
                    d[j] = d[j-1] + d[j];
            }
        }
        return d[n-1];
    }
};

int main(){
    return 0;
}
