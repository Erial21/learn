#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> map;
        for (auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        for (auto it = map.begin();it != map.end();++it) {
            res.push_back(it->second);
        }
        return res;
    }
};

int main() {
    vector<string>strs;
    strs.push_back("eat");
    strs.push_back("ate");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("bat");
    strs.push_back("nat");
    vector<vector<string>> str;
    Solution* solution = new Solution();
    str = solution->groupAnagrams(strs);
    vector<vector<string >>::iterator iter;
    vector<string>::iterator i;
    for (iter = str.begin(); iter != str.end(); ++iter) {
        for (i = (*iter).begin(); i < (*iter).end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
    }

    return 0;
}