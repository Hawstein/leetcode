#include <iostream>
using namespace std;

class Solution {
public:
    bool isAlphanumeric(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            return true;
        return false;
    }
    bool equal(char a, char b){
        if(a > b){
            char t = a;
            a = b;
            b = t;
        }
        return (a == b) || (a+32 == b);
    }
    bool isPalindrome(string s) {
        if(s == "") return true;
        int i=0, j=s.length()-1;
        while(i < j){
            while(i<j && !isAlphanumeric(s[i])) ++i;
            while(i<j && !isAlphanumeric(s[j])) --j;
            if(!equal(s[i], s[j])) return false;
            ++i; --j;
        }
        return true;
    }
};

int main(){
    return 0;
}
