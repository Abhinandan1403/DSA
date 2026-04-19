class Solution {
bool static comp(vector<int>&v1, vector<int>&v2) {
    return v1[1]<v2[1];
    
}
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0 ;
        int lastFinish = intervals[0][1];
        for(int i = 1 ;i<intervals.size() ; i++ ){
            if(intervals[i][0]<lastFinish){
                ans++;
            }
            else{
                lastFinish = intervals[i][1];
            }
        }
        return ans;
    }
};