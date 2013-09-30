#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        int n = strs.size();
        int len = strs[0].length();
        for(int i=1; i<n; ++i){
            for(int j=0; j<len; ++j){
                if(strs[0][j] != strs[i][j]){
                    len = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, len);
    }
};

int main(){
    return 0;
}
