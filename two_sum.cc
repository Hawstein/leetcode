#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int> > num;
        for(int i=0; i<numbers.size(); ++i)
            num.push_back(make_pair(numbers[i], i+1));
        
        sort(num.begin(), num.end());
        int id1 = -1, id2 = -1;
        int i = 0, j = num.size() - 1;
        while(i < j){
            if(num[i].first+num[j].first == target){
                id1 = min(num[i].second, num[j].second);
                id2 = max(num[i].second, num[j].second);
                break;
            }
            else if(num[i].first+num[j].first > target)
                --j;
            else
                ++i;
        }
        vector<int> ans;
        ans.push_back(id1);
        ans.push_back(id2);
        return ans;
    }
};

int main(){
    return 0;
}
