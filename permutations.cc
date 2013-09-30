#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > permute(vector<int> &num){
        
    }
    vector<vector<int> > permute1(vector<int> &num){
        vector<vector<int> > ans;
        for(int i=0; i<num.size(); ++i){
            vector<int> t = num;
            int v = t[i];
            t.erase(t.begin()+i);
            vector<vector<int> > part_ans = permute1(t);
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
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
    vector<vector<int> > permute2(vector<int> &num){
        vector<vector<int> > ans;
        int n = num.size();
        for(int i=n-1; i>=0; --i){
            swap(num[i], num[n-1]);
            int v = num.back();
            num.pop_back();
            vector<vector<int> > part_ans = permute2(num);
            if(part_ans.empty()){
                vector<int> t(1, v);
                ans.push_back(t);
            }
            else{
                for(int j=0; j<part_ans.size(); ++j){
                    part_ans[j].push_back(v);
                    ans.push_back(part_ans[j]);
                }
            }
            num.push_back(v);
            swap(num[i], num[n-1]);
        }
        return ans;
    }
};

int main(){
    return 0;
}
