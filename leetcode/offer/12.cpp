#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class BestSolution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (dfs(board, word, 0, i, j)) return true;
        return false;
    }
    int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }; //方向数组
    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y)
    {
        if (board[x][y] != word[u]) return false;
        if (u == word.size() - 1)   return true;
        board[x][y] = '.';
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            //出界或者走到已经搜索过的位置
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.')  continue;
            //继续查找，如果正确直接回溯，不需要把board[x][y]改回来
            if (dfs(board, word, u + 1, a, b)) return true;
        }
        board[x][y] = word[u];
        return false;
    }
};

class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for (int i = 0;i < row;++i) {
            for (int j = 0;j < col;++j) {
                if (dfs(board, word, i, j, 0)) {
                    return 1;
                }
            }
        }
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[k]) {
            return 0;
        }
        if (k == word.size() - 1) {
            return 1;
        }
        board[i][j] = '\0';
        if (dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1)
            || dfs(board, word, i, j - 1, k + 1) || dfs(board, word, i, j + 1, k + 1)) {
            return true;
        }
        board[i][j] = word[k];
        return false;
    }
};


