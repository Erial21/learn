#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        //words放入map中，方便检索
        unordered_map<string, int> wordMap;
        for (string w : words) {
            //计算单词在wordMap中的数量
            wordMap[w]++;
        }
        int m = words[0].size();//每个单词的长度
        int windowLen = words.size() * m;//滑动窗口长度
        unordered_map<string, int> tmp;//临时哈希表，存放子串单词
        //窗口滑动
        for (int start = 0;start + windowLen <= s.size();++start) {
            tmp.clear();//清空从窗口取出的子串
            int j;
            //子串进行比对，j每次增加单个单词长度
            for (j = 0;j < windowLen;j += m) {
                string t = s.substr(start + j, m);
                //如果t能在字典wordMap上找到对应的，则在临时表上做标记
                if (wordMap[t]) {
                    tmp[t]++;//做标记
                    //验证同一个单词数量是否多于字典
                    if (tmp[t] > wordMap[t]) {
                        break;
                    }
                }
                //没有对应的则直接跳出本次循环
                else {
                    break;
                }
            }
            //如果遍历到结尾，则把窗口的起始位置给到结果res
            if (j == windowLen) {
                res.push_back(start);
            }
        }
        return res;
    }
};



int main() {
    vector<string> s;
    s.push_back("sdflkj");
    s.push_back("sdkljfls");
    cout << s.size() << endl;
    cout << s[0].size() << endl;
    return 0;

}