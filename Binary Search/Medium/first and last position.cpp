class Solution {
public:
    // TC: O(log n) + O(log n) = O(log n)
    // SC: O(1)
    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.size() == 0) return {-1, -1};

        int low = 0, high = nums.size() - 1;
        int ans1 = -1, ans2 = -1;

        // 1) Find FIRST occurrence (leftmost)
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target) {
                if(nums[mid] == target) ans1 = mid;  // store possible answer
                high = mid - 1;                      // move left
            } 
            else {
                low = mid + 1;
            }
        }

        // 2) Find LAST occurrence (rightmost)
        low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] <= target) {
                if(nums[mid] == target) ans2 = mid;  // store possible answer
                low = mid + 1;                       // move right
            } 
            else {
                high = mid - 1;
            }
        }

        return {ans1, ans2};
    }
};
