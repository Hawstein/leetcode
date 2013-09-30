#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        return _subsets(S);
    }
    vector<vector<int> > _subsets(vector<int> &S){
        vector<vector<int> > ans;
        if(!S.empty()){
            int v = S.back();
            S.pop_back();
            vector<vector<int> > part_ans = _subsets(S);
            if(part_ans.empty()){
                vector<int> t;
                ans.push_back(t);
                t.push_back(v);
                ans.push_back(t);
            }
            else{
                for(int i=0; i<part_ans.size(); ++i){
                    ans.push_back(part_ans[i]);
                    part_ans[i].push_back(v);
                    ans.push_back(part_ans[i]);
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
