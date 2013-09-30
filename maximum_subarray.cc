#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int cur_sum = 0, max_sum = -2000000000;
        for(int i=0; i<n; ++i){
            if(cur_sum <= 0)
                cur_sum = A[i];
            else
                cur_sum += A[i];
            if(cur_sum > max_sum)
                max_sum = cur_sum;
        }
        return max_sum;
    }
};

int main(){
    Solution sln;
    int A[] = {
        -2,-1,-3,4,-1,2,1,-5,4
    };
    cout<<sln.maxSubArray(A, 3)<<endl;
    return 0;
}
