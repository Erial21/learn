#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < n;++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int right = n - 1;
            int target = -nums[i];
            for (int left = i + 1;left <= right;++left) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    continue;
                }
                //right向左
                while (left<right && nums[left] + nums[right]>target) {
                    --right;
                }
                if (left == right) {
                    break;
                }
                if (nums[left] + nums[right] == target) {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                }
            }
        }
        return ans;
    }
};