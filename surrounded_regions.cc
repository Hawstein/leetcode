#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.empty()) return;
        vector<vector<char> > vis = board;
        pair<int, int> *st = new pair<int, int>[board.size()*board[0].size()];
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(vis[i][j] == 'O' && board[i][j] == 'O'){
                    st[0] = make_pair(i, j);
                    vector<vector<char> > t = board;
                    if(_solve(t, i, j, st, 0, vis))
                        board = t;
                }
            }
        }
        delete[] st;
    }
    bool _solve(vector<vector<char> > &board, int i, int j, pair<int, int> *st, int top, vector<vector<char> > &vis){
        while(top != -1){
            pair<int, int> pos = st[top--];
            i = pos.first;
            j = pos.second;
            
            if(i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1)
                return false;
            board[i][j] = 'X';
            vis[i][j] = 'X';
            if(board[i-1][j] == 'O')
                st[++top] = make_pair(i-1, j);
            if(board[i+1][j]== 'O')
                st[++top] = make_pair(i+1, j);
            if(board[i][j-1] == 'O')
                st[++top] = make_pair(i, j-1);
            if(board[i][j+1] == 'O')
                st[++top] = make_pair(i, j+1);
        }
        return true;
    }

    void solve1(vector<vector<char> > &board) {
        if (board.empty()) return; 
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || i == N-1 || j == 0 || j == M-1)
                    bfs(board, i, j);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'V') board[i][j] = 'O';
    }

    void bfs(vector<vector<char> > &board, int i, int j)
    {
        if (board[i][j] != 'O')
            return;
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        int N = board.size(), M = board[0].size();
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if (board[i][j] == 'V') // important to recheck!
                continue;
            board[i][j] = 'V';
            if (i > 0 && board[i-1][j] == 'O')
                q.push(make_pair(i-1, j));
            if (i < N-1 && board[i+1][j] == 'O')
                q.push(make_pair(i+1, j));
            if (j > 0 && board[i][j-1] == 'O')
                q.push(make_pair(i, j-1));
            if (j < M-1&& board[i][j+1] == 'O')
                q.push(make_pair(i, j+1));
        }
    }
};

int main(){
    return 0;
}
