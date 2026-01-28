class Solution {
public:
    // TC: O(log n) average, O(n) worst (when many duplicates)
    // SC: O(1)
    bool search(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return true;  // target found

            // if low, mid, high are same -> can't decide sorted part, shrink range
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // left half is sorted
            if(nums[mid] >= nums[low]) {
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;   // target in left part
                } else {
                    low = mid + 1;    // target in right part
                }
            }
            // right half is sorted
            else {
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;    // target in right part
                } else {
                    high = mid - 1;   // target in left part
                }
            }
        }

        return false;  // not found
    }
};
