class Solution {
public:
    // TC: O(log n)  (binary search)
    // SC: O(1)
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        // edge cases
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // check if mid is the single element
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // before single element: pairs start at even index
            // after single element: pairs start at odd index
            if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
               (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;   // single element is on right side
            }
            else {
                high = mid - 1;  // single element is on left side
            }
        }

        return -1; // should not happen for valid input
    }
};
