class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        for (int i=0;i<n;i++){
            ans[2*i]= nums[i];
            ans[2*i+1]=nums[i+n];
            // Steps:  i=0 → ans[0]=2, ans[1]=3
                    // i=1 → ans[2]=5, ans[3]=4
                    // i=2 → ans[4]=1, ans[5]=7


        }
        return ans;
    }
};