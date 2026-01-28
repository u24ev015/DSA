class Solution {
public:
    // TC: O(log n)  (binary search)
    // SC: O(1)
    int findMin(vector<int>& nums) {

        int low = 0, high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            // if mid element is bigger than last element,
            // minimum lies in right half
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;  // minimum lies in left half (including mid)
        }

        return nums[low];  // low == high -> index of minimum
    }
};
