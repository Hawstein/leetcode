#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> elem;
        if(numRows < 1) return ans;
        elem.push_back(1);
        ans.push_back(elem);
        for(int i=2; i<=numRows; ++i) {
            elem.clear();
            elem.push_back(1);
            vector<int> pre = ans.back();
            for(int j=1; j<i-1; ++j) {
                elem.push_back(pre[j-1]+pre[j]);
            }
            elem.push_back(1);
            ans.push_back(elem);
        }
        return ans;
    }
};

int main() {
    return 0;
}
