#include <bits/stdc++.h>
//本质就是通过每一个回文子串中心向两边查询

class Solution {
   public:
    int countSubstrings(std::string s) {
        int n = s.size(), ans = 0;
        // i是当前回文子串的中心，本质是遍历所有回文子串的中心
        int i;
        for (i = 0; i < 2 * n - 2; ++i) {
            // r 在字串偶数和奇数时是不同的
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
    }
};