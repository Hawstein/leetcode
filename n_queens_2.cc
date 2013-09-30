#include <iostream>
#include <cstring>
using namespace std;

class Solution{
public:
    int totalNQueens(int n){
        return totalNQueens2(n);
    }        
    int totalNQueens1(int n){
        int C[n], tot = 0;
        memset(C, -1, sizeof(C));
        search1(0, n, tot, C);
        return tot;
    }
    void search1(int cur, int n, int &tot, int C[]){
        if(cur == n){
            ++tot;
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
            if(ok) search1(cur+1, n, tot, C);
        }
    }
    int totalNQueens2(int n){
        int tot = 0;
        search2(n, 0, 0, 0, tot);
        return tot;
    }
    // if n > 32, use long long for row,ld,rd
    void search2(int n, int row, int ld, int rd, int &tot){
        if(row == (1<<n)-1){
            ++tot;
            return;
        }
        int avail = ~(row | ld | rd);
        for(int i=n-1; i>=0; --i){
            int pos = 1<<i;
            if(avail & pos)
                search2(n, row|pos, (ld|pos)<<1, (rd|pos)>>1, tot);
        }
    }
};

int main(){
    Solution sln;
    cout<<sln.totalNQueens(8)<<endl;
    return 0;
}
