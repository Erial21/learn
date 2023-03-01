#include <iostream>
#include <vector>
// 快慢指针，快指针在遍历数组的过程中把元素换到慢指针处，
// 遍历完数组后，把让慢指针把剩下数组元素替换为0；
class Solution {
   public:
    void moveZeroes(std::vector<int>& nums) {
        // 双指针
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        for (; slow < nums.size(); slow++) {
            nums[slow] = 0;
        }
    }
};

class Solution2 {
   public:
    void moveZeroes(std::vector<int>& nums) {
        // 双指针
        int slow = 0;
        int fast = 0;

        for (fast; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                std::swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};