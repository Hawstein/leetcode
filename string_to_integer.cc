#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL) return -1;
        while(*str == ' ') ++str;
        int sign = 0;
        if(*str=='+' || *str=='-'){
            if(*str == '+') sign = 0;
            else sign = 1;
            ++str;
        }
        long long ans = 0;
        while(*str){
            if(*str<'0' || *str>'9')
                break;
            ans = 10 * ans + *str - '0';
            if(!sign && ans > INT_MAX){
                ans = INT_MAX;
                break;
            }
            if(sign && -ans < INT_MIN){
                ans = INT_MIN;
                break;
            }
            ++str;
        }
        if(sign) ans = -ans;
        return ans;
    }
};

int main(){
    Solution sln;
    cout<<sln.atoi(" +12*3");
    return 0;
}
