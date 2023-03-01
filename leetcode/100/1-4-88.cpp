#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int cur = nums1.size() - 1;

        // 因为是要在nums1上添加，一定要以j为条件，否则可能造成nums2没有转移完。
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[cur] = nums1[i];

                cur--;
                i--;
            } else {
                nums1[cur] = nums2[j];

                cur--;
                j--;
            }
        }
    }
};

// 代码有看不懂的地方一定要私聊咨询吴师兄呀
// 合并两个有序数组( LeetCode 88
// ):https://leetcode-cn.com/problems/merge-sorted-array/
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 索引从有序数组 nums1 有效元素的末端开始
        // 数组的下标索引从零开始计数
        // 索引   0    1     2
        // 数组 [ 1 ,  2  ,  3 ]
        int i = m - 1;

        // 索引从有序数组 nums2 的末端开始
        int j = n - 1;

        // 从有序数组 nums1 最末端的位置开始保存元素
        int cur = nums1.size() - 1;

        // 通过循环把 num2 的元素都移动到 num1 中
        while (j >= 0) {
            // 比较 num1 和 num2 中当前的元素大小

            // 如果 num1 中的索引位置为 i 的元素大于 num2 中索引位置为 j 的元素
            // 为了防止越界 i 必须是大于等于 0
            if (i >= 0 && nums1[i] > nums2[j]) {
                // 把 num1 中的索引位置为 i 的元素复制到索引为 cur 的位置
                // 此时 cur 的元素已经确定下来
                nums1[cur] = nums1[i];

                // 接下来去确定 cur 前面一个元素应该放什么数字
                cur--;
                // 此时，索引 i 需要向前移动
                i--;
                // 否则，如果 num1 中的索引位置为 i 的元素小于或者等于 num2
                // 中索引位置为 j 的元素
            } else {
                // 把 num2 中的索引位置为 j 的元素复制到索引为 cur 的位置
                nums1[cur] = nums2[j];
                // 接下来去确定 cur 前面一个元素应该放什么数字
                cur--;
                // 此时，索引 j 需要向前移动
                j--;
            }
        }
    }
};
