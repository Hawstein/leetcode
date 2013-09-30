#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int> > q;
        q.push(make_pair(start, 1));
        while(!q.empty()){
            pair<string, int> front = q.front();
            q.pop();
            string word = front.first;
            for(int i=0; i<word.size(); ++i){
                char before = word[i];
                for(char c='a'; c<='z'; ++c){
                    word[i] = c;
                    if(word == end)
                        return front.second+1;
                    if(dict.find(word) != dict.end()){
                        q.push(make_pair(word, front.second+1));
                        dict.erase(word);
                    }
                }
                word[i] = before;
            }
        }
        return 0;
    }
};

int main(){
    return 0;
}
