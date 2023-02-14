#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<deque>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') {
            ++left;
        }
        while (left <= right && s[right] == ' ') {
            --right;
        }
        deque<string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                d.push_front(word);
                word = "";
            }
            else {
                word += c;
            }
            ++left;
        }
        //原数组最后一个词在循环里不能放入队列
        d.push_front(word);

        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) {
                ans += ' ';
            }
        }
        return ans;
    }
};