#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };

    static bool cmp(Interval a, Interval b){//去掉static会错误，因为sort没有this指针,无法传递cmp
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int n = intervals.size();
        int start = intervals[0].start, end = intervals[0].end;
        for(int i=0; i<n-1; ++i){
            if(end < intervals[i+1].start){
                Interval elem(start, end);
                ans.push_back(elem);
                start = intervals[i+1].start;
                end = intervals[i+1].end;
            }
            else{
                end = max(end, intervals[i+1].end);
            }
            
        }
        Interval elem(start, end);
        ans.push_back(elem);
        return ans;
    }
};

int main(){
    return 0;
}
