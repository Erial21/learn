#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0;i < row;++i) {
            for (int j = 0;j < col;++j) {
                if(i==0&&j==0){
                    
                }else if(i==0&&j>0){
                    grid[i][j]+=grid[i][j-1];
                }else if(i>0&&j==0){
                    grid[i][j]+=grid[i-1][j];
                }else{
                    //状态转移方程
                    //要算出grid[i][j]需要
                    //grid[i-1][j]或grid[i][j-1] 加上 grid[i][j]
                    grid[i][j]=max(grid[i-1][j],grid[i][j-1])+grid[i][j];
                }
            }
        }
        return grid[row-1][col-1];
    }
};