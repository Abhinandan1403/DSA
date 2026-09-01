class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = -1;
        int val = 0;
        for(int i = 0 ; i<gas.size() ; i++){
            val += (gas[i] - cost[i]);

            if(val>=0 && idx == -1){
                idx = i;
            }
            else if(val<0){
                idx = -1;
                val = 0;
            }
        }

        val = 0;
        for(int i = idx ; i<=idx+gas.size() ; i++){
            int j = i%gas.size();
            val += (gas[j]-cost[j]);
            if(val<0)return -1;
        }
        return idx;
    }
};