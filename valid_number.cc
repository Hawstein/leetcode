#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        if(!s || !*s) return false;
        bool pre = false, suf = false;
        while(*s == ' ') ++s; // 去掉前导空格
        if(!*s) return false;
        if(*s=='+' || *s=='-') ++s;
        if(!*s) return false;
        while(*s && *s>='0' && *s<='9'){
             ++s;
             pre = true;
        }
        if(!*s) return true;
        if(*s == '.'){
            ++s;
            while(*s && *s>='0' && *s<='9'){
                 ++s;
                 suf = true;
            }
            if(!pre && !suf) return false;
            if(!*s) return true;
        }
        if(*s == 'e'){
            if(!pre && !suf) return false;
            ++s;
            if(*s=='+' || *s=='-') ++s;
            if(!*s) return false;
            bool exp = false;
            while(*s && *s>='0' && *s<='9'){
                ++s;
                exp = true;
            }
            if(!exp) return false;
            if(!*s) return true;
        }
        while(*s == ' ') ++s; // 去掉后导空格
        if(!*s) return true;
        return false;
    }
};

int main(){
    return 0;
}
