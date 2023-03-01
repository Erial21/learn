#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int right = 0;

        int n = nums.size();
        for(right;right<n;right++){
            if( right == 0 || nums[right]!=nums[right-1]){
                nums[left]=nums[right];
                left++;
            }
        }
        return left;
    }
};