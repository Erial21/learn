#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    //不进行重复检查的方法
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 1e7;
        sort(nums.begin(), nums.end());
        //绝对值对比
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(ans - target)) {
                ans = cur;
            }
        };
        for (int i = 0;i < n;++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return target;
                }
                update(sum);
                if (sum > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = 1e7;
    sort(nums.begin(), nums.end());
    auto update = [&](int cur) {
        if (abs(cur - target) < abs(ans - target)) {
            ans = cur;
        }
    };
    for (int i = 0;i < n;++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return target;
            }
            update(sum);
            if (sum > target) {
                while (left < right-1 && nums[right - 1] == nums[right]) {
                    --right;
                }
                //仅仅这样不够，需要再减一次，才是不同的元素
                --right;
            }
            else {
                while (left+1 < right && nums[left] == nums[left + 1]) {
                    ++left;
                }
                //仅仅这样不够，需要再加一次，才是不同的元素
                ++left;
            }
        }
    }
    return ans;
}


int main() {
    vector<int>nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);

    Solution* solution = new Solution();
    /*
    int ans = solution->threeSumClosest(nums, 1);
    cout << ans << endl;
     */
    int ans = threeSumClosest(nums, 1);
    cout << ans << endl;

    return 0;

}