class Solution {
    bool static comp(vector<int>& v1, vector<int>& v2){
        if(v1[0] != v2[0])return v1[0]<v2[0];
        return v1[1]>v2[1];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0 ;
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1 ; i<intervals.size() ; i++){
            if(l<=intervals[i][0] && intervals[i][1]<=r){
                ans++;
            }
            else{
                l=intervals[i][0];
                r=intervals[i][1];
            }
        }
        return intervals.size()-ans;
    }
};