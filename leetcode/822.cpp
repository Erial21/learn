#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> set;
        int i, cSize;
        cSize = fronts.size();
        for (i = 0;i < cSize;++i) {
            if (fronts[i] == backs[i]) {
                set.insert(fronts[i]);
            }
        }
        int res = INT_MAX;
        for (int x : fronts) {
            //find()返回一个迭代器
            //如果没有找到元素，则返回结束迭代器set.end()
            //所以这里是==
            if (set.find(x) == set.end()) {
                res = min(res, x);
            }
        }
        for (int x : backs) {
            if (set.find(x) == set.end()) {
                res = min(res, x);
            }
        }
        return res;
    }
};