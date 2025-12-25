// Simulation / Brute-force mutation
// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         long long sum=0;
//         sort(happiness.begin(),happiness.end(),greater<int>());
//         if(k<=1){
//             sum = happiness[0];    
//         }else{
//         for(int i=0;i<k;i++){
//             sum += happiness[i];
//             for(int j=0; j<happiness.size();j++){
//                 happiness[j] = happiness[j]-1;
//             }
//         }}
//         return sum;
//     }
// };
// Greedy + arithmetic / optimized calculation ✅
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort happiness in descending order so we pick the happiest people first
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long sum = 0;

        // Pick up to k people (or less if array is smaller)
        for (int i = 0; i < k && i < happiness.size(); i++) {

            // Each previous pick reduces happiness by 1
            int current = happiness[i] - i;

            // Only add positive happiness
            if (current > 0)
                sum += current;
            else
                break; // Further values will only be smaller
        }

        // Return the maximum total happiness
        return sum;
    }
};
