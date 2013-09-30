#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int left = 1, right = 1;
        int xx = x / 10;
        while(xx != 0) {
            left *= 10;
            xx /= 10;
        }
        while(right < left) {
            if((x/left)%10 != (x/right)%10)
                return false;
            left /= 10;
            right *= 10;
        }
        return true;
    }
};

int main() {
    return 0;
}
