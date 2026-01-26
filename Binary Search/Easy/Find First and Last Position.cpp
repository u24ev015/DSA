class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Handle empty input
        if (nums.empty())
            return {-1, -1};

        int low = 0, high = nums.size() - 1;
        int ans1 = -1, ans2 = -1;

        // Binary search for FIRST occurrence of target
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    ans1 = mid;      // store potential first index
                high = mid - 1;     // move left
            } else {
                low = mid + 1;
            }
        }

        // Reset pointers
        low = 0;
        high = nums.size() - 1;

        // Binary search for LAST occurrence of target
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    ans2 = mid;      // store potential last index
                low = mid + 1;      // move right
            } else {
                high = mid - 1;
            }
        }

        return {ans1, ans2};
    }
};
