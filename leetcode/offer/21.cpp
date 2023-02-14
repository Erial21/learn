#include<bits/stdc++.h>

using namespace std;

//解法2: 双指针,一头一尾
//左边指向偶数,停下,右边指向奇数,也停下
//两个交换位置.

//解法1:
//添加两个数组, 把奇数偶数分别放入
//最后合并两个数组
//时间复杂度还可以
//内存占用大
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> vec1;
        vector<int> vec2;
        for (auto it = nums.begin();it != nums.end();++it) {
            if ((*it) % 2 != 0) {
                vec1.push_back(*it);
            }
            else {
                vec2.push_back(*it);
            }
        }
        vec1.insert(vec1.end(), vec2.begin(), vec2.end());
        return vec1;
    }
};


//废案
//1000ms的执行时间
//18.3m的内存占用
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> vec1;
        for (auto it = nums.begin();it != nums.end();) {
            if ((*it) % 2 != 0) {
                vec1.push_back(*it);
                //重点,只用nums.erase(it)的话,迭代器会报错
                //negative size param
                //加上++it来防止出错,又会大大增加执行时间.
                nums.erase(it++);
            }
            it++;
        }
        for (auto it = nums.begin();it != nums.end();++it) {
            vec1.push_back(*it);
        }
        return vec1;
    }
};