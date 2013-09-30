#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int p = m + n - 1;
        int i = m - 1, j = n - 1;
        while(i>=0 && j>=0) {
            if(A[i] > B[j])
                A[p--] = A[i--];
            else
                A[p--] = B[j--];
        }
        while(j >= 0)
            A[p--] = B[j--];
    }
};

int main() {
    return 0;
}
