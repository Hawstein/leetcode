#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        bool found = false;
        _solveSudoku(board, 0, found);
    }
    void _solveSudoku(vector<vector<char> > &board, int pos, bool &found){
        if(pos == 81){
            found = true;
            return;
        }
        int r = pos/9, c = pos%9;
        if(board[r][c] != '.'){
            _solveSudoku(board, pos+1, found);
        }
        else{
            bool map[10];
            memset(map, false, sizeof(map));
            // row
            for(int j=0; j<9; ++j)
                if(board[r][j] != '.')
                    map[board[r][j]-'0'] = true;
            // col
            for(int i=0; i<9; ++i)
                if(board[i][c] != '.')
                    map[board[i][c]-'0'] = true;
            // small square
            int rr = r, cc = c;
            while(rr%3 != 0) --rr;
            while(cc%3 != 0) --cc;
            for(int i=rr; i<rr+3; ++i)
                for(int j=cc; j<cc+3; ++j)
                    if(board[i][j] != '.')
                        map[board[i][j]-'0'] = true;
            
            for(int i=1; i<=9 && !found; ++i){
                if(!map[i]){
                    board[r][c] = i + '0';
                    _solveSudoku(board, pos+1, found);
                    if(found) break;
                    board[r][c] = '.';
                }
            }
        }
        
    }
};

int main(){
    string s[9] = {
         "..9748...",
         "7........",
         ".2.1.9...",
         "..7...24.",
         ".64.1.59.",
         ".98...3..",
         "...8.3.2.",
         "........6",
         "...2759.."
    };
    vector<vector<char> > board;
    for(int i=0; i<9; ++i){
        vector<char> t;
        for(int j=0; j<9; ++j){
            t.push_back(s[i][j]);
        }
        board.push_back(t);
    }
    Solution sln;
    sln.solveSudoku(board);
    return 0;
}
