class Solution {
public:
    //斐波那契数
    int fib(int n) {
        int a=0,b=1,c;
        if(n<2)return n;
        for(int i=2;i<=n;++i){
            c=(a+b)%1000000007;
            a=b;
            b=c;
        }
        return c;
    }
};