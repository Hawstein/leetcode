// tmp[i]是串s[0..i]的回文划分
// 那么对于tmp[i+1],考察s[j..i+1]是否为回文。
// 如果是，则把tmp[j-1]中每一个字符串数组添加上s[j..i+1]后，加到t[j]中。
// 答案即为tmp[len-1],len为s长度
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    typedef vector<string> vs;
    typedef vector<vector<string> > vvs;
    vector<vector<string> > partition(string s) {
        int len = s.length();
        //tmp[i] is the partition of s[0..i]
        //so the answer is tmp[len-1]
        vector<vvs> tmp(len);
        for(int i=0; i<len; ++i){
            for(int j=0; j<=i; ++j){
                // s[j..i] is palindrome
                int x = j, y = i;
                bool palind = true;
                while(x <= y){
                    if(s[x] != s[y]){
                        palind = false;
                        break;
                    }
                    ++x; --y;
                }
                if(palind){ // s[j..i] is palindrome
                    string sji = s.substr(j, i-j+1);
                    if(j == 0){
                        vs t;
                        t.push_back(sji);
                        tmp[i].push_back(t);
                    }
                    else{
                        vvs tt = tmp[j-1];
                        for(int k=0; k<tt.size(); ++k){
                            vs t = tt[k];
                            t.push_back(sji);
                            tmp[i].push_back(t);
                        }
                    }
                }
            }// for j
        }// for i
        return tmp[len-1];
    }
};

int main(){
    Solution sln;
    vector<vector<string> > res = sln.partition("abaddaba");
    int n = res.size();
    for(int i=0; i<n; ++i){
        vector<string> t = res[i];
        int len = t.size();
        for(int j=0; j<len; ++j){
            cout<<t[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
