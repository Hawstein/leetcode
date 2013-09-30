#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        return longestPalindrome3(s);
    }
    string longestPalindrome1(string s){
        int start = 0, max_len = 0;
        int n = s.length();
        bool d[n][n];
        for(int i=n-1; i>=0; --i){
            for(int j=i; j<n; ++j){
                if(i == j)
                    d[i][j] = true;
                else if(i+1 == j)
                    d[i][j] = s[i]==s[j];
                else
                    d[i][j] = (s[i]==s[j]) && d[i+1][j-1];

                if(d[i][j] && j-i+1 > max_len){
                    start = i;
                    max_len = j - i + 1;
                }
            }
        }
        return s.substr(start, max_len);
    }
    string longestPalindrome2(string s){
        int start = 0, max_len = 0;
        int n = s.length();
        for(int i=n-1; i>=0; --i){
            for(int j=0; j<=1; ++j){
                bool dp = s[i]==s[i+j];
                if(dp && j+1 > max_len){
                    start = i;
                    max_len = j+1;
                }
                for(int k=1; dp && i-k>=0; ++k){
                    dp = s[i-k]==s[i+j+k];// when meet s[n]='\0',dp=false
                    if(dp && j+2*k+1 > max_len){
                        start = i-k;
                        max_len = j+2*k+1;
                    }
                }
            }
            if(max_len == n) break;
        }
        return s.substr(start, max_len);
    }
    // Manacher's Algorithm
    string longestPalindrome3(string s){
        int n = s.length();
        n = 2 * n + 1;
        int mx = 0, id = 0, d[n];
        for(int i=0; i<n; ++i){
            d[i] = mx>i ? min(d[2*id-i], mx-i) : 1;
            int left = i - d[i];
            int right = i + d[i];
            for(; left>=0 && right<n; --left,++right){
                if(left%2==0 || s[left/2]==s[right/2])//'#' or same char
                    ++d[i];
                else
                    break;
            }
            if(i+d[i] > mx){
                mx = i + d[i];
                id = i;
            }
        }
        id = 0;
        for(int i=0; i<n; ++i)
            if(d[i] > d[id])
                id = i;
        int max_len = d[id] - 1;
        int start = id/2 - max_len/2;
        return s.substr(start, max_len);
    }
};

int main(){
    string s = "abcdcb";

    Solution sln;
    cout<<sln.longestPalindrome(s)<<endl;
    return 0;
}
