#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        int left = -1, right = -1;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target == A[mid]){
                left = searchInsert(A, low, mid-1, (float)target-0.5);
                right = searchInsert(A, mid+1, high, (float)target+0.5) - 1;
                break;
            }
            if(target > A[mid]) low = mid + 1;
            else high = mid - 1;
        }
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
    int searchInsert(int A[], int low, int high, float target) {
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target > A[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main(){
    int A[] = {
        5, 7, 7, 8, 8, 8
    };
    Solution sln;
    vector<int> ans = sln.searchRange(A, 6, 10);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
