class Solution {
public:
    // TC: O(n log n)  (map find/insert takes log n)
    // SC: O(n)        (stores elements in map)
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int> mpp;  // value -> index

        for(int i = 0; i < nums.size(); i++) {
            int more = target - nums[i];   // required value

            if(mpp.find(more) != mpp.end()) {
                return {mpp[more], i};     // found pair
            }

            mpp[nums[i]] = i;              // store current value index
        }

        return {};
    }
};
