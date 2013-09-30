#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans;
        vector<int> elem;
        sort(candidates.begin(), candidates.end());
        _combinationSum(ans, elem, candidates, 0, target);
        return ans;
    }
    void _combinationSum(vector<vector<int> > &ans, vector<int> &elem, vector<int> &candidates, int start, int target){
        if(target == 0){
            ans.push_back(elem);
            return;
        }
        for(int i=start; i<candidates.size()  && target-candidates[i]>=0; ++i){
            elem.push_back(candidates[i]);
            _combinationSum(ans, elem, candidates, i, target-candidates[i]);
            elem.pop_back();
        }
    }
};

int main(){
    return 0;
}
