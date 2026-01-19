class Solution {
public:
    // Calculates total hours needed if Koko eats at speed = mid
    long long func(int mid, vector<int>& piles) {
        long long sum = 0;

        // For each pile, compute hours using ceiling division
        for (int i = 0; i < piles.size(); i++) {
            sum += ceil((double)piles[i] / (double)mid);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // Maximum possible eating speed
        int maxi = *max_element(piles.begin(), piles.end());

        int low = 1, high = maxi;

        // Binary search on eating speed
        while (high >= low) {
            int mid = low + (high - low) / 2;

            // If required hours exceed h, speed is too slow
            if (func(mid, piles) > h) {
                low = mid + 1;
            }
            // Otherwise, try smaller speed
            else {
                high = mid - 1;
            }
        }

        // Minimum valid eating speed
        return low;
    }
};
