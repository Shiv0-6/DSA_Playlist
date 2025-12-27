class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        // Create a count array to store how many times each number appears
        // Size n+1 because numbers are from 1 to n; index 0 is unused
        vector<int> count(n + 1, 0);
        
        // This will store the result: [duplicate, missing]
        vector<int> ans(2, 0);
        
        // Step 1: Count occurrences of each number in nums
        for (int x : nums) {
            count[x]++;   // Increment the count of number x
        }
        // for (int i = 0; i < n; i++) {
        //     int x = nums[i];  // take current number
        //     count[x]++;       // increase its count
        // }

        
        // Step 2: Scan count array to find duplicate and missing numbers
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                // If a number appears twice, it is the duplicate
                ans[0] = i;
            }
            if (count[i] == 0) {
                // If a number appears zero times, it is missing
                ans[1] = i;
            }
        }
        
        return ans;
    }
};
