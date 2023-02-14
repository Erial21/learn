class Solution {
public:
    int numWays(int n) {
        if (n <= 1)return 1;
        if (n == 2)return 2;
        // 当有一级台阶,跳法有a=1种
        // 当有两级台阶,跳法有两次一级和一次两级,2种.
        // 三级台阶时,跳法有先跳一级,再跳两级或先跳两级再跳一级或只用一级的方式跳上.
        int a = 1, b = 2, c;
        //从第3项开始计算到第n项
        for (int i = 3;i <= n;++i) {
            //只需要看最后两层台阶怎么上,是上一级台阶,还是最后上两级
            //也就是说a可以看作只剩一级的跳法,b是还剩两级的跳法
            //a+b就是一共有多少种跳法.
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};