#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int d[len1+1][len2+1];
        for(int i=0; i<=len1; ++i)
            d[i][0] = i;
        for(int j=0; j<=len2; ++j)
            d[0][j] = j;
        for(int i=1; i<=len1; ++i)
            for(int j=1; j<=len2; ++j){
                d[i][j] = (word1[i-1]==word2[j-1]) ? d[i-1][j-1] : d[i-1][j-1]+1;// 替换
                d[i][j] = min(d[i][j], d[i-1][j]+1); // 删除
                d[i][j] = min(d[i][j], d[i][j-1]+1); // 插入
            }
        return d[len1][len2];
    }
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
    int minDistance2(string word1, string word2){
        int len1 = word1.length();
        int len2 = word2.length();
        int d[len2+1];
        for(int j=0; j<=len2; ++j)
            d[j] = j;
        for(int i=1; i<=len1; ++i){
            int x = i - 1;
            d[0] = i;
            for(int j=1; j<=len2; ++j){
                x = (word1[i-1]==word2[j-1]) ? x : x+1;
                x = min(x, d[j-1]+1);
                x = min(x, d[j]+1);
                swap(x, d[j]);
            }
        }
        return d[len2];
    }
};

int main(){
    Solution sln;
    string s1 = "inten";
    string s2 = "execu";
    cout<<sln.minDistance(s1, s2)<<endl;
    cout<<sln.minDistance2(s1, s2)<<endl;
    return 0;
}
