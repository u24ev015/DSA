class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else if (!temp.empty()) {
                words.push_back(temp);
                temp = "";
            }
        }

        // push last word if exists
        if (!temp.empty())
            words.push_back(temp);

        reverse(words.begin(), words.end());

        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) ans += " ";
            ans += words[i];
        }

        return ans;
    }
};
