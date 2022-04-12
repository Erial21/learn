#include<iostream>
#include<vector>

using namespace std;

class SolutionNormal {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0;right < n;++right) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                ++left;
            }
        }
    }
};
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        //如果不是设置成n而是n-1的话，left最终少返回1.
        int right = n;
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                --right;
            }
            else {
                ++left;
            }
        }
        return left;
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                --right;
            }
            else {
                ++left;
            }
        }
        return left;
    }
};