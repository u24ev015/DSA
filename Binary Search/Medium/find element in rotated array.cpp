class Solution {
public:
    // TC: O(log n)
    // SC: O(1)
    int search(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;  // found target

            // left part is sorted
            if(nums[mid] >= nums[low]) {

                // target lies in sorted left range
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // right part is sorted
            else {

                // target lies in sorted right range
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;  // target not found
    }
};
