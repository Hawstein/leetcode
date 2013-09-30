#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.empty()) return digits;
        int n = digits.size();
        int pos = n - 1;
        for(; pos>=0 && digits[pos]==9; --pos);
        if(pos == -1){
            vector<int> ans(n+1, 0);
            ans[0] = 1;
            return ans;
        }
        else{
            digits[pos] += 1;
            for(int i=pos+1; i<n; ++i)
                digits[i] = 0;
            return digits;
        }
    }
};

int main(){
    return 0;
}
