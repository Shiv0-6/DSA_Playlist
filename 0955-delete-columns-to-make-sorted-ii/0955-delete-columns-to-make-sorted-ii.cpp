class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n= strs.size();
        int m=strs[0].size();
        int ans=0;
        vector<bool>sorted(n-1,false);//check for sorted
        for(int col=0;col<m;col++){
            bool needDelete=false;
            for(int row=0;row<n-1;row++)//check which indices should be delete
                if(!sorted[row] && strs[row][col]>strs[row+1][col]){
                    needDelete= true;
                    break;
                }
                if (needDelete==true){//check for  deletion
                    ans++;
                }
                else //update sorted array
                for(int row=0;row<n-1;row++){
                    if(strs[row][col]<strs[row+1][col]){
                        sorted[row]=true;
                    }
                }
        }
        return ans;
    }
};
