class Solution {
public:
    // TC: O(log n)  (binary search)
    // SC: O(1)
    int peakIndexInMountainArray(vector<int>& nums) {

        int n = nums.size();

        // edge cases
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;         // peak at start (extra safe)
        if(nums[n - 1] > nums[n - 2]) return n - 1; // peak at end (extra safe)

        int low = 1, high = n - 2;  // peak can't be outside this range in mountain array

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // check if mid is peak
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            // if we are in decreasing part, move left
            if(nums[mid] < nums[mid - 1])
                high = mid - 1;
            else
                low = mid + 1;  // otherwise we are in increasing part, move right
        }

        return -1; // should never happen for valid mountain array
    }
};
