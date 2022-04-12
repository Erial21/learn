#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        //建立一个已遍历的表
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(0, 0, 0, 0, visited, m, n, k);
    }
    int dfs(int i, int j, int si, int sj, vector<vector<bool>>& visited, int m, int n, int k) {
        if (i > m || j > n || si + sj > k || visited[i][j]) {
            return 0;
        }
        visited[i][j] = 1;
        /*
        算i和j个位数和十位数相加的和
        当19->20的时候，和从10->2，此情况当机器人前进时，si-8;
        当19->20以外的时候，和只增加1，此情况机器人前进时，si+1;
         */
        return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k)
            + dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
    }
};