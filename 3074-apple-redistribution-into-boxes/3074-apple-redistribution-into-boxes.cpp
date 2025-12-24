class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int  count=0;
        int TotalApples=0;
        int sumCap=0;
        for (int i=0;i<apple.size();i++){
            TotalApples += apple[i];
        }
        sort(capacity.begin(),capacity.end(),greater<int>());
        for (int i=0;i<capacity.size();i++){
            if(sumCap<TotalApples){
                sumCap +=capacity[i];
                count++;
            }
        }
        return count;
    }
};