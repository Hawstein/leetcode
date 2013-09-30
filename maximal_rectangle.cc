#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix){
        return maximalRectangle1(matrix);
    }
    int maximalRectangle1(vector<vector<char> > &matrix){
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int p[m+1][n+1];
        int max_area = -2000000000;
        for(int i=0; i<=m; ++i)
            p[i][0] = 0;
        for(int j=0; j<=n; ++j)
            p[0][j] = 0;
        // part sum
        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j)
                p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + matrix[i-1][j-1]-'0';
        
        for(int i=1; i<=m; ++i)
            for(int j=i; j<=m; ++j){
                int len = j - i + 1;
                int cur_area = 0;
                for(int k=1; k<=n; ++k){
                    int t = p[j][k] - p[j][k-1] - p[i-1][k] + p[i-1][k-1];
                    if(t == len)
                        cur_area += t;
                    else
                        cur_area = 0;

                    if(cur_area > max_area)
                        max_area = cur_area;
                }
            }
        return max_area;
    }
    int maximalRectangle2(vector<vector<char> > &matrix){
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int d[m][n];
        for(int j=0; j<n; ++j){
            int t = 0;
            for(int i=0; i<m; ++i){
                if(matrix[i][j] == '0')
                    t = 0;
                else
                    ++t;
                d[i][j] = t;
            }
        }
        int max_area = 0, cur_area = 0;
        for(int i=0; i<m; ++i){
            cur_area = largestRectangleArea(d[i], n);
            if(cur_area > max_area)
                max_area = cur_area;
        }
        return max_area;
    }
    int largestRectangleArea(int* height, int n){
        if(n <= 0) return 0;
        int h[n], id[n], pos = -1;
        int max_area = 0, cur_area = 0;
        for(int i=0; i<n; ++i){
            if(pos==-1 || height[i]>h[pos]){
                ++pos;
                h[pos] = height[i];
                id[pos] = i;
            }
            else if(height[i] < h[pos]){
                int lastId = 0;
                while(pos!=-1 && height[i]<h[pos]){
                    lastId = id[pos];
                    cur_area = h[pos] * (i - lastId);
                    if(cur_area > max_area)
                        max_area = cur_area;
                    --pos;
                }
                ++pos;
                h[pos] = height[i];
                id[pos] = lastId;
            }
        }
        while(pos != -1){
            cur_area = h[pos] * (n - id[pos]);
            if(cur_area > max_area)
                max_area = cur_area;
            --pos;
        }
        return max_area;
    }
};

int main(){
    
    return 0;
}
