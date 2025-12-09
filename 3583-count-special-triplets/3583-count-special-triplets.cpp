#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // Count occurrences of numbers to the left and right of each position
        unordered_map<int, int> leftCount, rightCount;
        
        // First, count all elements (will be in rightCount initially)
        for (int num : nums) {
            rightCount[num]++;
        }
        
        long long result = 0;
        
        // For each position j as the middle element
        for (int j = 0; j < n; j++) {
            // Remove current element from rightCount
            rightCount[nums[j]]--;
            
            // Calculate target value (2 * nums[j])
            long long target = (long long)nums[j] * 2;
            
            // Check if target fits in int range
            if (target <= 100000) {  // Based on constraints
                int targetInt = (int)target;
                
                // Count how many i on left have value = target
                int leftMatches = leftCount[targetInt];
                
                // Count how many k on right have value = target
                int rightMatches = rightCount[targetInt];
                
                // Add to result
                result = (result + (long long)leftMatches * rightMatches) % MOD;
            }
            
            // Add current element to leftCount
            leftCount[nums[j]]++;
        }
        
        return result;
    }
};