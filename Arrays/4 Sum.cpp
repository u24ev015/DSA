class Solution {
public:
    // TC: O(n^3) + O(n log n) ≈ O(n^3)
    // SC: O(1) extra (ignoring output)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> v;
        int n = nums.size();

        sort(nums.begin(), nums.end()); // required for 2-pointer + skipping duplicates

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            for(int j = i + 1; j < n; j++) {

                if(j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

                int k = j + 1, l = n - 1;  // find remaining 2 numbers using 2-pointer

                while(k < l) {
                    long long sum = 0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum > target) l--;       // need smaller sum
                    else if(sum < target) k++;  // need bigger sum
                    else {
                        v.push_back({nums[i], nums[j], nums[k], nums[l]});

                        k++;
                        l--;

                        // skip duplicates for k and l to avoid same quadruplets
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }

        return v;
    }
};
