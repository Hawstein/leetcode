#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int n = s.length();
        if(n==0 || n==1 || nRows==1) return s;
        string t = "";
        int gap = (nRows - 1) * 2, m = n;
        while(m % gap != 0) ++m;
        m /= gap;
        int d[m+1];
        for(int i=0; i<m+1; ++i)
            d[i] = i * gap;
        for(int i=0; i<nRows; ++i){
            if(i==0 || i==nRows-1){
                for(int j=0; j<m+1; ++j){
                    if(d[j]+i < n)
                        t = t + s[d[j]+i];
                }
            }
            else{
                for(int j=0; j<m+1; ++j){
                    if(d[j]-i >= 0 && d[j]-i < n)
                        t = t + s[d[j]-i];
                    if(d[j]+i < n)
                        t = t + s[d[j]+i];
                }
            }
        }
        return t;
    }
};

int main(){
    Solution sln;
    cout<<sln.convert("PAYPALISHIRING", 3);
    return 0;
}
