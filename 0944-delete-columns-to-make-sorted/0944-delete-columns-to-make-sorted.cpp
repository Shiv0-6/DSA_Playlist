// class Solution{
//     public:
//     int minDeletionSize(vector<string>& strs){
//         int n= strs.size();
//         int m= strs[0].size();
//         int ans=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n-1;j++){
//                 if(strs[j][i] > strs[j+1][i]){
//                    ans++;
//                 break;  
//                 }   
//             }
//         }
//          return ans;
//     }
   
// };
class Solution {
    public:
    int minDeletionSize(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size(); 
    int ans = 0;
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n-1; row++) {
            if (strs[row][col] > strs[row+1][col]) {
                ans++;
                break; // no need to check further in this column
            }
        }
    }
    return ans;
    }
};
