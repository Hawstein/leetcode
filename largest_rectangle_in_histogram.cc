#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height){
        int n = height.size();
        if(n <= 0) return 0;
        int h[n], id[n], pos = -1;
        int max_area = 0, cur_area = 0;
        for(int i=0; i<n; ++i){
            if(pos==-1 || height[i]>h[pos]){
                ++pos;
                h[pos] = height[i];
                id[pos] = i;
            }
            else if(height[i] < h[pos]){
                int lastId = 0;
                while(pos!=-1 && height[i]<h[pos]){
                    lastId = id[pos];
                    cur_area = h[pos] * (i - lastId);
                    if(cur_area > max_area)
                        max_area = cur_area;
                    --pos;
                }
                ++pos;
                h[pos] = height[i];
                id[pos] = lastId;
            }
        }
        while(pos != -1){
            cur_area = h[pos] * (n - id[pos]);
            if(cur_area > max_area)
                max_area = cur_area;
            --pos;
        }
        return max_area;
    }
};

int main(){
    return 0;
}
