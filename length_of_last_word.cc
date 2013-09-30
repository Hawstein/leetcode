#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s == NULL) return 0;
        int n = strlen(s);
        if(n == 0) return 0;
        int pos = n - 1;
        while(pos>=0 && s[pos]==' ') --pos;
        int cnt = 0;
        for(int i=pos; i>=0; --i){
            if(s[i] == ' ') break;
            ++cnt;
        }
        return cnt;
    }
};

int main(){
    Solution sln;
    cout<<sln.lengthOfLastWord("   dafda adf ");
    return 0;
}
