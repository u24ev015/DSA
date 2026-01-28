class Solution {
public:
    // TC: O(n)  (two pointers)
    // SC: O(1)
    vector<int> twoSum(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;  // pointers at both ends

        while(left < right) {
            int sum = nums[left] + nums[right];

            if(sum > target) right--;       // need smaller sum
            else if(sum < target) left++;   // need bigger sum
            else break;                     // found answer
        }

        return {left + 1, right + 1};  // 1-based indexing as per problem
    }
};
