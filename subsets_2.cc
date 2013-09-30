#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        return _subsetsWithDup(S);
    }
    vector<vector<int> > _subsetsWithDup(vector<int> &S){
        vector<vector<int> > ans;
        if(!S.empty()){
            int v = S.back();
            S.pop_back();
            vector<vector<int> > part_ans = _subsetsWithDup(S);
            if(part_ans.empty()){
                vector<int> t;
                ans.push_back(t);
                t.push_back(v);
                ans.push_back(t);
            }
            else{
                set<vector<int> > svi;
                for(int i=0; i<part_ans.size(); ++i){
                    if(svi.find(part_ans[i]) == svi.end()){
                        ans.push_back(part_ans[i]);
                        svi.insert(part_ans[i]);
                    }
                    part_ans[i].push_back(v);
                    if(svi.find(part_ans[i]) == svi.end()){
                        ans.push_back(part_ans[i]);
                        svi.insert(part_ans[i]);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
