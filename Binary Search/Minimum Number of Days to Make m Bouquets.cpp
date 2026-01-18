class Solution {
public:

   // This function checks how many bouquets can be made

   int flowers(vector<int>& arr, int days, int m, int k)
   {
        int count = 0;    // counts consecutive bloomed flowers
        int noOfB = 0;    // total number of bouquets possible

        for (int i = 0; i < arr.size(); i++)
        {
            // if flower blooms on or before 'days'
            if (arr[i] <= days)
                count++;   
            else
            {
                // segment breaks → calculate bouquets from previous segment
                noOfB += count / k;
                count = 0;
            }
        }

        // add bouquets from the last segment
        noOfB += count / k;

        return noOfB; 
   }
   
   int minDays(vector<int>& bloomDay, int m, int k) {

        // If total required flowers (m * k) exceed available flowers
        if (m > bloomDay.size() / k) 
            return -1;

        // Binary search boundaries:
        // minimum day = earliest bloom
        // maximum day = latest bloom
        int low  = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (high >= low)
        {
            int mid = low + (high - low) / 2;

            // If we can make at least 'm' bouquets by 'mid' days
            if (flowers(bloomDay, mid, m, k) >= m)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
   }
};
