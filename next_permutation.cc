#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 找到第一个比x大的数
    int bsearch(vector<int> &num, int low, int high, int x) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(x < num[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
    void nextPermutation(vector<int> &num) {
        if(num.empty()) return;
        int i = num.size() - 1;
        for(; i>0; --i) {
            if(num[i-1] < num[i]) {
                // 找到第一个比num[i-1]大的，然后与它交换
                int p = bsearch(num, i, num.size()-1, num[i-1]);
                swap(num[i-1], num[p]);
                sort(num.begin()+i, num.end());
                break;
            }
        }
        // next permutation does not exist
        if(i == 0) sort(num.begin(), num.end());
    }
};

int main() {
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(5);
    Solution sln;
    sln.nextPermutation(num);
    for(int i=0; i<3; ++i)
        cout<<num[i]<<" ";
    return 0;
}
