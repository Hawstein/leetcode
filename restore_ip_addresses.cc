#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<string> restoreIpAddresses(string s){
        vector<string> ans;
        string ip;
        restoreIpAddressesRe(s, ans, ip, 0, 0);
        return ans;
    }
    void restoreIpAddressesRe(string &s, vector<string>& ans, string &ip, int deep, int start){
        if(deep == 4 || start == s.size()){
            if(deep == 4 && start == s.size())
                ans.push_back(ip);
            return;
        }
        int num = 0;
        for(int i=start; i<=start+2 && i<s.size(); ++i){
            num = num * 10 + s[i] - '0';
            if(num >= 0 && num <=255){
                int orig = ip.size();
                if(orig != 0) ip.push_back('.');
                ip += s.substr(start, i-start+1);
                restoreIpAddressesRe(s, ans, ip, deep+1, i+1);
                ip.resize(orig);
                if(num == 0) break;
            }
        }
    }
};

int main(){
    return 0;
}
