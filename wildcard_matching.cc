#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = NULL, *pp = NULL;
        while(*s) {
            if(*p == '?' || *p == *s) {
                ++s;
                ++p;
            }
            else if(*p == '*') {
                while(*p == '*') ++p;
                if(!*p) return true;
                ss = s;
                pp = p;
            }
            else if(*s != *p && ss) {
                s = ++ss;
                p = pp;
            }
            else {
                return false;
            }
        }
        while(*p == '*') ++p;
        return (!*p);
    }
};

int main() {
    return 0;
}
