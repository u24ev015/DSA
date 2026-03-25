class Solution {
public:
    void solve( vector<vector<int>>& ans,vector<int>& temp,vector<int>& nums,vector<int>& used)
    {
       if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;            
        }

        for(int i=0;i<nums.size();i++)
        {
            if(used[i]!=0)continue;

            if(i>0 && nums[i]==nums[i-1] && !used[i-1])continue;

            temp.push_back(nums[i]);
            used[i]=1;

            solve(ans,temp,nums,used);
            temp.pop_back();
            used[i]=0;

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    vector<int>temp;
    vector<int>used(nums.size(),0); 
    solve(ans,temp,nums,used);
    return ans;   
    }
};
