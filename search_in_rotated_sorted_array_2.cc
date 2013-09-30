#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target == A[mid]) return true;

            // for duplicates
            int tmp = mid;
            while(tmp >= low && A[tmp] == A[low] ) --tmp;
            if(tmp < low) {
                low = mid + 1;
                continue;
            }
            
            if(A[mid] > A[low]){
                if(target < A[mid] && target >= A[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else{
                if(target > A[mid] && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    int a[] = { 2,2,2,2,2,2,2,2,3,2 };
    Solution sln;
    cout<<sln.search(a, 10, 3);
    return 0;
}
