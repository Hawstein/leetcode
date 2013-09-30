#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end = -1;
        for(int i=0; i<n; ++i){
            if(A[i] != elem)
                A[++end] = A[i];
        }
        return end+1;
    }
};

int main(){
    return 0;
}
