#include <iostream>
using namespace std;

class Solution {
public:
    typedef long long LL;
    int sqrt(int x) {
        if(x < 0) return -1;
        if(x==0 || x==1) return x;
        int low = 0, high = x/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            LL xt = (LL)mid * mid;
            if(xt == x) return mid;
            if(x > xt) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
    // 牛顿迭代法
    int sqrt(int x) {
        if (x == 0) return 0;
        double last = 0;
        double res = 1;
        while ((int)res != (int)last)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};

int main(){
    return 0;
}
