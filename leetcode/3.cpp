#include<iostream>
#include<unordered_set>

using namespace std;
//滑动窗口算法。
class Solution {
public:
    int longString(string s) {
        unordered_set<char> ch;
        int n = s.size();

        int rk = -1, i = 0, ans = 0;
        for (i = 0;i < n;++i) {
            if (i != 0) {
                //当发现重复时，左指针右移，集合删除左指针原位的值
                ch.erase(s[i - 1]);
            }
            /* 
            检测rk+1是否合法 && 下一个字母是否已存在于哈希集合
             */
            while (rk + 1 < n && !ch.count(s[rk + 1])) {
                //合法就加入哈希集合
                ch.insert(s[rk + 1]);
                ++rk;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    };
};

int main() {
    string s = "abcbbaaabcdd";
    Solution* solution = new Solution();
    cout << solution->longString(s) << endl;


}