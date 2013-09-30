#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
    double pow(double x, int n){
        if(n == 0) return 1;
        if(abs(x) < 0.0000001 && n < 0) return 0;

        bool sign = n < 0 ? true : false;
        n = abs(n);
        double ans = 1.0;
        while(n > 0){
            if(n & 1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return sign ? 1.0/ans : ans;
    }
};

int main(){
    return 0;
}
