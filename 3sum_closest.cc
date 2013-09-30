#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.empty()) return 0;
        int ans = 0, diff = INT_MAX;
        sort(num.begin(), num.end());
        for(int i=num.size()-1; i>0; --i){
            int v = num[i];
            int j=0, k=i-1;
            while(j < k){
                int sum = num[j] + num[k];
                if(sum == target-v){
                    return target;
                }
                else if(sum > target-v)
                    --k;
                else
                    ++j;
                if(abs(sum+v-target) < diff){
                    ans = sum + v;
                    diff = abs(sum + v - target);
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
