#include<bits/stdc++.h>

using namespace std;
//
//还没写好。
//
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int p = left;
        //随机交换一个主元的值
        //如果没有随机化，则当原数组已经排好了
        //就会造成时间复杂度达到最高O(n^2)
        //不断地遍历
        swap(nums[left], nums[left + rand() % (right - left)]);
        while (left < right) {
            while (left < right && nums[left] < nums[p]) {
                ++left;
            }
            while (left<right && nums[right]>nums[p]) {
                --right;
            }
            swap(nums[left], nums[right]);
        }
        swap(nums[left], nums[p]);
        p = left;
        quickSort(nums, left, p - 1);
        quickSort(nums, p + 1, right);
    }
};