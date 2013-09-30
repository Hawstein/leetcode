#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans, part;
        if(num.empty()) return ans;
        sort(num.begin(), num.end());
        int pre = INT_MIN;
        while(!num.empty()){
            int v = num.back();
            num.pop_back();
            if(v < 0) break; // 已排过序，前面不可能再找出2个与它相加得0
            if(v == pre) continue; // 去重
            pre = v;
            part = twoSum(num, -v);
            if(part.empty()) continue;
            for(int j=0; j<part.size(); ++j){
                part[j].push_back(v);
                ans.push_back(part[j]);
            }
            part.clear();
        }
        return ans;
    }
    vector<vector<int> > twoSum(vector<int> &num, int target) {
        int i = 0, j = num.size() - 1;
        vector<vector<int> > ans;
        vector<int> elem(2);
        while(i < j){
            if(num[i]+num[j] == target){
                elem[0] = num[i];
                elem[1] = num[j];
                ans.push_back(elem);
                while(i<j && num[i+1]==num[i]) ++i;// avoid duplicates
                while(i<j && num[j-1]==num[j]) --j;
                ++i; --j;
            }
            else if(num[i]+num[j] > target)
                --j;
            else
                ++i;
        }
        return ans;
    }
};

int main(){
    int a[] = {
        -1, 0, 1//, 2, -1, -4, 9, -5
    };
    vector<int> num(a, a+3);
    Solution sln;
    vector<vector<int> > ans = sln.threeSum(num);
    if(!ans.empty()){
        for(int i=0; i<ans.size(); ++i){
            for(int j=0; j<ans[0].size(); ++j){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
