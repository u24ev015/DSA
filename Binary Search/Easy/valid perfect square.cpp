class Solution {
public:
    // TC: O(log n)  (binary search)
    // SC: O(1)
    bool isPerfectSquare(int num) {

        long long low = 1, high = num;  // search range for sqrt(num)

        while(low <= high) {
            long long mid = low + (high - low) / 2;  // avoid overflow
            long long sq = mid * mid;                // use long long to prevent overflow

            if(sq == num) return true;       // perfect square found
            else if(sq > num) high = mid - 1; // go left (smaller mid)
            else low = mid + 1;              // go right (bigger mid)
        }

        return false;  // no integer square root exists
    }
};
