class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int i=0,j=0;
    int len=0,maxi=0;
    unordered_map<char,int>mpp;
    while(j<s.size())
    {
        if(mpp.find(s[j])==mpp.end())
        {
            len++;
            maxi=max(maxi,len);
            mpp[s[j]]++;
            j++;
        }
        else
        {
            mpp.erase(s[i]);
            i++;
            len--;
        }
    }
    return maxi;
    }
};
