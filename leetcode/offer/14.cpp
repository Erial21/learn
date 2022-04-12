#include<iostream>
#include<vector>

using namespace std;

//经过数学计算，发现当长度为2.7时，乘积为极大值
//所以当长度为2或3时，有绳子最大乘积
class Solution {
public:
    int cuttingRope(int n) {
        //1,2,3时
        if (n <= 3)  return n - 1;

        //当余下最后一截为2
        if (n % 3 == 2) {
            return pow(3, n / 3) * 2;
        }
        //当余下最后一截为1，需要和一截长度为3的平分为2.
        else if (n % 3 == 1) {
            return pow(3, (n / 3 - 1)) * 2 * 2;
        }
        //能够被长度为3等分的。
        else {
            return pow(3, n / 3);
        }
    }
};

int main() {
    Solution* solution = new Solution();
    cout << solution->cuttingRope(2) << endl;
    cout << solution->cuttingRope(6) << endl;
    return 0;
}