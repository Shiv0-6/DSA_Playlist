class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // penalty: running score
        // decreases for 'Y' (good to stay open), increases for 'N' (better to close)
        int penalty = 0;

        // bestHrs: the hour at which the shop should close for minimum penalty
        int bestHrs = 0;

        // mini: the minimum penalty seen so far
        int mini = 0;

        // Loop through each hour/customer
        for (int i = 0; i < n; i++) {

       

            // Update penalty based on customer type
            if (customers[i] == 'Y') {
                // 'Y' means customer comes → reducing penalty if we stay open
                penalty -= 1;
            } else {
                // 'N' means no customer → penalty increases if we stay open
                penalty += 1;
            }
            // Check if the current penalty is lower than any seen before
            // If yes, update mini and record the closing hour
            // Note: currently your check happens BEFORE updating penalty,
            // so the "bestHrs" may lag by one hour
            if (penalty < mini) {
                mini = penalty;
                bestHrs = i + 1;  // i+1 because closing is after current hour
            }
        }

        // Return the hour with minimum penalty
        return bestHrs;
    }
};
