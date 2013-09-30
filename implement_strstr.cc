#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while(true){
            char *p = haystack, *q = needle;
            while(*q && *p == *q){
                ++p;
                ++q;
            }
            if(!*q) return haystack;
            if(!*p) return NULL;
            ++haystack;
        }
    }
    
    char* strStr1(char* haystack, char* needle){// kmp
        //partial matching table
        int n = strlen(needle);
        if(!*needle || n==0) return haystack;
        int pm[n];
        for(int i=1; i<=n; ++i){
            int len = 0;
            for(int j=1; j<i; ++j){//compare prefix and suffix
                int k = 0;
                for(; k<j && needle[k]==needle[k+i-j]; ++k);
                if(k == j) len = j;
            }
            pm[i-1] = len;
        }

        while(*haystack){
            if(*(haystack) != *(needle)){
                ++haystack;
                continue;
            }
            else{
                int i = 0;
                for(; *(haystack+i)==*(needle+i); ++i)
                    if(!*(needle+i+1)) return haystack;
                haystack += i - pm[i-1];
            }
        }
        return NULL;
    }
};

int main(){
    Solution sln;
    char* c = "";
    if(!*c) cout<<true;
    return 0;
}
