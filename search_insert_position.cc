#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target == A[mid]) return mid;
            if(target > A[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main(){
    int A[] = {
        1, 3, 5, 6
    };
    Solution sln;
    cout<<sln.searchInsert(A, 4, 7)<<endl;
    return 0;
}
