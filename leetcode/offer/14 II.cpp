#include<iostream>
#include<vector>

using namespace std;

//经过数学计算，发现当长度为2.7时，乘积为极大值
//所以当长度为2或3时，有绳子最大乘积

//用100000007 能省那么一点点内存。
class Solution {
public:
    int cuttingRope(int n) {
        //1,2,3时
        if (n <= 3)  return n - 1;
        int b = n % 3, mod = 1e9 + 7;
        long ret = 1;
        int inNum = n / 3;;
        //循环求余
        //起始i为1，少乘一个，与原值得余数分。
        for (int i = 1;i < inNum;++i) {
            ret = 3 * ret % (1000000007);
        }
        //整除就直接乘上开头省略得3
        if (b == 0) {
            return (int)(ret * 3 % (1000000007));
        }
        //余1的情况，3*1要分配成2*2
        if (b == 1) {                 
            ret = ret * 2 % (1000000007);
            ret = ret * 2 % (1000000007);
            return (int)ret;
        }
        //余2
        if (b == 2) {
            ret = ret * 3 % (1000000007);
            ret = ret * 2 % (1000000007);
            return (int)ret;
        }
        return 0;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << solution->cuttingRope(127) << endl;
    cout << solution->cuttingRope(120) << endl;
    cout << solution->cuttingRope(108) << endl;
    return 0;
}