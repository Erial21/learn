#include <bits/stdc++.h>

class Solution {
   public:
    int balancedString(std::string s) {
        int n = s.length();
        int m = n / 4;
        int cnt['X']{};

        for (char c : s) {
            ++cnt[c];
        }

        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) {
            return 0;
            // 符合要求
        }

        int ans = n;
        int left = 0;

        for (int right = 0; right < n; right++) {
            --cnt[s[right]];  // 枚举子串右端点，将枚举的字符从cnt数组中减去
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m &&
                   cnt['R'] <= m) {
                ans = std::min(ans, right - left + 1);
                ++cnt[s[left++]];
                // 涉及运算符优先问题，此处先调用left的位置，在进行left的自加
                // ++cnt[s[left]];
                // left++;
            }
        }
        return ans;
    }
};
