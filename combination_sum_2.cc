#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> elem;
        set<vector<int> > s;
        sort(num.begin(), num.end());
        _combinationSum2(ans, num, elem, target, 0, s);
        return ans;
    }
    void _combinationSum2(vector<vector<int> > &ans, vector<int> &num, vector<int> &elem, int target, int start, set<vector<int> > &s){
        if(target == 0){
            if(s.find(elem) == s.end()){
                ans.push_back(elem);
                s.insert(elem);
            }
        }
        for(int i=start; i<num.size() && target-num[i]>=0; ++i){
            elem.push_back(num[i]);
            _combinationSum2(ans, num, elem, target-num[i], i+1, s);
            elem.pop_back();
        }
    }
};

int main(){
    return 0;
}
