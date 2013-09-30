#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n){
        vector<vector<string> > ans;
        int *C = new int[n];
        memset(C, -1, sizeof(C));
        search(0, n, C, ans);
        delete[] C;
        return ans;
    }
    void search(int cur, int n, int* C, vector<vector<string> > &ans){
        if(cur == n){
            vector<string> vs;
            for(int i=0; i<n; ++i){
                string s(n, '.');
                s[C[i]] = 'Q';
                vs.push_back(s);
            }
            ans.push_back(vs);
            return;
        }
        for(int i=0; i<n; ++i){
            bool ok = true;
            C[cur] = i;
            for(int j=0; j<cur; ++j)
                if(C[cur]==C[j] || cur-j==C[cur]-C[j] || cur-j==C[j]-C[cur]){
                    ok = false;
                    break;
                }
            if(ok) search(cur+1, n, C, ans);
        }
    }
};


int main(){
    Solution sln;
    sln.solveNQueens(2);
    return 0;
}
