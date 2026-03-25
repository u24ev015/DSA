class Solution {
public:
    string getHint(string secret, string guess) {
    int cows=0,bulls=0;
    for(int i=0;i<secret.size();i++)
    {
        if(secret[i]==guess[i])
        bulls++;
    }
    vector<int>secret1(10,0),guess1(10,0);
    for(int i=0;i<secret.size();i++)
    {
        if(secret[i]!=guess[i])
        {secret1[secret[i]-'0']++;
        guess1[guess[i]-'0']++;}

    }    
    for(int i=0;i<secret1.size();i++)
    {
        cows+=min(secret1[i],guess1[i]);
    }

    return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
