class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long result = 0;
        int sign = 1;

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // Check sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Read digits
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Handle overflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;

            i++;
        }

        return result * sign;
    }
};
