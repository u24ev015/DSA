class Solution {
public:
    // TC: O(log n)  (binary search)
    // SC: O(1)
    int searchInsert(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                high = mid - 1;      // search left half
            }
            else if(nums[mid] < target) {
                low = mid + 1;       // search right half
            }
            else {
                return mid;          // target found
            }
        }

        return low;  // correct insert position
    }
};
