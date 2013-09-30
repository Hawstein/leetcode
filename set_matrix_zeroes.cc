#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool clear_first_row = false;
        bool clear_first_col = false;
        for(int j=0; j<n && !clear_first_row; ++j)
            clear_first_row = (matrix[0][j] == 0);
        for(int i=0; i<m && !clear_first_col; ++i)
            clear_first_col = (matrix[i][0] == 0);

        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        for(int i=1; i<m; ++i)
            if(matrix[i][0] == 0)
                for(int j=1; j<n; ++j)
                    matrix[i][j] = 0;

        for(int j=1; j<n; ++j)
            if(matrix[0][j] == 0)
                for(int i=1; i<m; ++i)
                    matrix[i][j] = 0;

        if(clear_first_row)
            for(int j=0; j<n; ++j)
                matrix[0][j] = 0;
        if(clear_first_col)
            for(int i=0; i<m; ++i)
                matrix[i][0] = 0;
    }
};

int main() {
    return 0;
}
