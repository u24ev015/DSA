class Solution {
public:
    void solve(set<vector<int>>& st,vector<int>temp,vector<int>& nums,int i)
    {
        if(i==nums.size())
        {
            st.insert(temp);
            return;
        }

        solve(st,temp,nums,i+1);

        temp.push_back(nums[i]);
        solve(st,temp,nums,i+1);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int>temp;
    set<vector<int>>st;
    solve(st,temp,nums,0);
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    }
};
