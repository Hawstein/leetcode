#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if(rowIndex < 0) return ans;
        ans.resize(rowIndex + 1);
        ans[0] = 1;
        for(int i=1; i<=rowIndex; ++i) {
            int tmp = 1;
            for(int j=1; j<i; ++j) {
                tmp += ans[j];
                swap(tmp, ans[j]);
            }
            ans[i] = 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}
