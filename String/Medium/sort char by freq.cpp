class Solution {
public:
    string frequencySort(string s) {
    map<char,int>mpp;
    multimap<int,char>mpp1;
    string s1="";
    for(int i=0;i<s.size();i++)
    {
    mpp[s[i]]++;
    }
    for (auto it = mpp.begin(); it != mpp.end(); ++it) 
    {
        mpp1.insert({it->second, it->first});
    }
    for (auto it = mpp1.begin(); it != mpp1.end(); ++it) 
    {
       s1.append(it->first,it->second);
    }
    reverse(s1.begin(),s1.end());
    return s1;

    }
};
