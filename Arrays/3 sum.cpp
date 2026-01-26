class Solution {
public:
    // TC: O(n^2) + O(n log n) ≈ O(n^2)
    // SC: O(1) extra (ignoring output vector)
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> v;
        int n = nums.size();

        sort(nums.begin(), nums.end());  // needed for 2-pointer + duplicate removal

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            int j = i + 1, k = n - 1;  // fix nums[i], find pair (nums[j], nums[k])

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0) k--;        // need smaller sum
                else if(sum < 0) j++;   // need bigger sum
                else {
                    v.push_back({nums[i], nums[j], nums[k]}); // found one triplet

                    j++; 
                    k--;

                    // avoid duplicate triplets
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return v;
    }
};
