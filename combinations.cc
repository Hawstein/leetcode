#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> elem;
        _combine(ans, elem, 1, n, k);
        return ans;
    }
    void _combine(vector<vector<int> > &ans, vector<int> &elem, int start, int n, int k){
        if(elem.size() == k){
            ans.push_back(elem);
            return;
        }
        for(int i=start; i<=n; ++i){
            elem.push_back(i);
            _combine(ans, elem, i+1, n, k);
            elem.pop_back();
        }
    }
};

int main(){
    return 0;
}
