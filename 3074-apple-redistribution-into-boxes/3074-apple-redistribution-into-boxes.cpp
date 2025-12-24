// class Solution {
// public:
//     int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
//         int  count=0;
//         int TotalApples=0;
//         int sumCap=0;
//         for (int i=0;i<apple.size();i++){
//             TotalApples += apple[i];
//         }
//         sort(capacity.begin(),capacity.end(),greater<int>());
//         for (int i=0;i<capacity.size();i++){
//             if(sumCap<TotalApples){
//                 sumCap +=capacity[i];// Loop continues to next box (if any), but we don’t need more boxes
//                 count++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int TotalApples = 0;     // total number of apples
        int sumCap = 0;          // cumulative capacity
        int count = 0;           // number of boxes used
        
        // Step 1: Sum all apples
        for (int i = 0; i < apple.size(); i++) {
            TotalApples += apple[i];
        }
        
        // Step 2: Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());
        
        // Step 3: Select boxes until total capacity >= total apples
        for (int i = 0; i < capacity.size(); i++) {
            sumCap += capacity[i];
            count++;
            if (sumCap >= TotalApples) {
                break; // no more boxes needed
            }
        }
        
        // Step 4: Return the minimum number of boxes used
        return count;
    }
};
