class Solution {
public:
    // TC: O(log n) average, O(n) worst (when many duplicates)
    // SC: O(1)
    int findMin(vector<int>& nums) {

        int low = 0, high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            // if nums[mid] == nums[high], can't decide the side -> shrink high
            if(nums[mid] == nums[high]) {
                high--;
            }
            // minimum is in right half
            else if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // minimum is in left half (including mid)
            else {
                high = mid;
            }
        }

        return nums[low];  // low == high -> minimum element index
    }
};
