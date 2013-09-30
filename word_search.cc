#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        int h[] = {
            -1, 1, 0, 0
        };
        int v[] = {
            0, 0, -1, 1
        };
        bool **visited = new bool*[m];
        for(int i=0; i<m; ++i){
            visited[i] = new bool[n];
            memset(visited[i], 0, n*sizeof(bool));
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == word[0]){
                    if(_exist(board, i, j, word, 1, h, v, visited))
                        return true;
                }
            }
        }
        for(int i=0; i<m; ++i)
            delete[] visited[i];
        delete[] visited;
        
        return false;
    }
    bool _exist(vector<vector<char> > &b, int i, int j, string word, int k, int h[], int v[], bool **vis){
        if(k == word.size()) return true;
        bool found = false;
        vis[i][j] = true;
        for(int x=0; x<4; ++x){
            int ii = i + h[x];
            int jj = j + v[x];
            if(ii>=0 && ii<b.size() && jj>=0 && jj<b[0].size() && b[ii][jj]==word[k] && !vis[ii][jj]){
                    if(_exist(b, ii, jj, word, k+1, h, v, vis)){
                        found = true;
                        break;
                    }
            }
        }
        vis[i][j] = false;
        return found;
    }
};

int main(){
    return 0;
}
