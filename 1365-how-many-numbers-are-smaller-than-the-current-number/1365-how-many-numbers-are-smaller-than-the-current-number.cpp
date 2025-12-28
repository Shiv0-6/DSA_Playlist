// Brute-Force
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans(n,0);
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(nums[i]>nums[j]){
//                     count++;
//                 }   
//             }
//             ans[i]=count;
//             count=0;//count reset
//         }
//         return ans;
//     }
// };

// Sorting + Hash map
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        // Step 1: Create a copy of nums and sort it
        // This helps us determine the relative order of each number
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        // Step 2: Create a hash map to store count of smaller numbers for each unique number
        unordered_map<int, int> countMap;
        for (int i = 0; i < n; i++) {
            // ------------------------------
            // Important line:
            // ------------------------------
            // Check if the number is NOT already in the map.
            // countMap.find(sortedNums[i]) returns an iterator:
            //   - If the number exists in the map, find() returns an iterator pointing to it
            //   - If the number does NOT exist, find() returns countMap.end()
            // Why this check?
            //   - The index of the first occurrence in the sorted array equals
            //     the count of smaller numbers.
            //   - If there are duplicates, we ONLY want the first occurrence
            //     to avoid overwriting the correct count.
            if (countMap.find(sortedNums[i]) == countMap.end()) {
                countMap[sortedNums[i]] = i; // Key = number, Value = count of smaller numbers
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = countMap[nums[i]]; // Fetch the precomputed count from the map
        }

        return ans;
    }
};
