//双指针
//一头一尾,向中间靠拢
//找到第一对就返回.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.begin()==nums.end()){
            return nums;
        }
        vector<int> vec;
        int left=0;int right = nums.size()-1;
        while(left<right){
            if(nums[left]+nums[right]>target){
                --right;
            }else if(nums[left]+nums[right]<target){
                ++left;
            }else if(nums[left]+nums[right]==target){
                vec.push_back(nums[left]);
                vec.push_back(nums[right]);
                return vec;
            }
        }
        return vec;
    }
};