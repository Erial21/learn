#include<iostream>
#include<vector>

using namespace std;

//二进制用为运算

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        //循环-1；用位运算把1删除得的同时，在结果上加1
        //时间复杂度ln n;
        while (n) {
            n &= n - 1;
            ++res;
        }
        return res;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        //循环比对，时间复杂度为k
        for (int i = 0;i < 32;++i) {
            if (n & (1 << i)) {
                ++res;
            }
        }
        return res;
    }
};


int main() {

}