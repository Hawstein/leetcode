#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution{
public:
    vector<vector<int> > permuteUnique(vector<int> &num){
        vector<vector<int> > ans;
        set<int> used;
        for(int i=0; i<num.size(); ++i){
            vector<int> t = num;
            int v = t[i];
            if(used.find(v) != used.end()) continue;
            used.insert(v);
            t.erase(t.begin()+i);
            vector<vector<int> > part_ans = permuteUnique(t);
            if(part_ans.empty()){
                vector<int> tt(1, v);
                ans.push_back(tt);
            }
            else{
                for(int j=0; j<part_ans.size(); ++j){
                    t = part_ans[j];
                    t.push_back(v);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
    vector<vector<int> > permuteUnique1(vector<int> &num){
        vector<vector<int> > ans;
        map<int, bool> mmap;
        for(int i=0; i<num.size(); ++i){
            vector<int> t = num;
            int v = t[i];
            if(mmap[v]) continue;
            mmap[v] = true;
            t.erase(t.begin()+i);
            vector<vector<int> > part_ans = permuteUnique1(t);
            if(part_ans.empty()){
                vector<int> tt(1, v);
                ans.push_back(tt);
            }
            else{
                for(int j=0; j<part_ans.size(); ++j){
                    t = part_ans[j];
                    t.push_back(v);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
