#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<string> letterCombinations(string digits) {
        char table[10][4] = {
            { ' ',0,0,0 },
            { 0,0,0,0 },
            { 'a','b','c',0 },
            { 'd','e','f',0 },
            { 'g','h','i',0 },
            { 'j','k','l',0 },
            { 'm','n','o',0 },
            { 'p','q','r','s' },
            { 't','u','v',0 },
            { 'w','x','y','z' }
        };
        vector<string> ans;
        string elem;
        _letterCombinations(ans, elem, digits, 0, table);
        return ans;
    }
    void _letterCombinations(vector<string> &ans, string &elem, string &digits, int pos, char table[][4]){
        if(pos == digits.length()){
            ans.push_back(elem);
            return;
        }
        int id = digits[pos] - '0';
        int n = 3;
        if(id == 0) n = 1;
        else if(id == 1) n = 0;
        else if(id==7 || id==9) n = 4;
        for(int i=0; i<n; ++i){
            int sz = elem.length();
            elem.push_back(table[id][i]);
            _letterCombinations(ans, elem, digits, pos+1, table);
            elem.resize(sz);
        }
    }
};

int main(){
    return 0;
}
