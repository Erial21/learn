#include <bits/stdc++.h>

using namespace std;

vector<int> computeTempArray(string pattern) {
    int size = pattern.size();
    vector<int> next(size);
    /* for (int i = 1, k = 0; i < size; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = next[k - 1];
        }
        if (pattern[i] == pattern[k]) {
            next[i] = ++k;
        } else {
            next[i] = k;
        }
    }
    return next; */
    int index = 0;
    for (int i = 1; i < size;) {
        if (pattern[i] == pattern[index]) {
            next[i] = index + 1;
            index++;
            i++;
        } else {
            if (index != 0) {
                index = next[index - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }
    return next;
}

/* int main(int argc, char const* argv[]) {
    std::string subS = "abcdabcy";

    std::vector<int> next = computeTempArray(subS);
    for (auto i = next.begin(); i != next.end(); i++) {
        std::cout << *i << ' ';
    }
    cout << endl;
    cout << next[4] << endl;
    cout << next[5] << endl;

    for (auto it : next) {
        cout << it << endl;
    }

    return 0;
} */

bool kmp(std::string text, std::string pattern) {
    vector<int> next = computeTempArray(pattern);
    int i = 0;
    int j = 0;
    while (i < text.size() && j < pattern.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }
    if (j == pattern.size()) {
        return true;
    }
    return false;
}

int main(int argc, char const* argv[]) {
    std::string str = "abcxabcdabcdabcy";
    std::string subString = "abcdabcy";

    bool result = kmp(str, subString);
    std::cout << result << std::endl;
    return 0;
}
