class Solution {
public:
    string convert(string s, int rows) {
    string s1="";
    if(rows==1)
    return s;
    int cycle=2*(rows-1);
    for(int i=0;i<rows;i++)
    {
        for(int j=i;j<s.size();j+=cycle)
        {
            s1.push_back(s[j]);
        

        int diag=j+cycle-2*i;
        if(i!=0 && i!=rows-1 && diag<s.size())
        {
            s1.push_back(s[diag]);
        }
        }

    }
    return s1;
    }
};
