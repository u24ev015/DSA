class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Edge case: only one element
        if (n == 1) return 0;

        // Check boundary elements
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return (n - 1);

        int low = 1, high = n - 2;

        // Binary search for a peak element
        while (high >= low) {
            int mid = low + (high - low) / 2;

            // If mid is greater than both neighbors, it's a peak
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            // If slope is decreasing, move left
            if (nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                high = mid - 1;
            }
            // Otherwise, move right
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};
