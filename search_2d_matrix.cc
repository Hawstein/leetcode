#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int i = mid/cols, j = mid%cols;
            if(target == matrix[i][j]) return true;
            if(target > matrix[i][j]) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main(){
    return 0;
}
