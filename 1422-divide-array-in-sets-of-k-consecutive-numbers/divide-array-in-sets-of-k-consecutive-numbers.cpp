class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0 ; i<nums.size() ; i++){
            if(mpp.find(nums[i]) == mpp.end())pq.push(nums[i]);
            mpp[nums[i]]++;
        }

        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            mpp[val]--;

            vector<int>v;
            if(mpp[val] > 0)v.push_back(val);

            for(int i = val+1 ; i<val+k ; i++){
                if(mpp.find(i) == mpp.end())return false;

                mpp[i]--;

                if(mpp[i]==0){
                    pq.pop();
                    mpp.erase(i);
                }
                else{
                    pq.pop();
                    v.push_back(i);
                }
            }

            for(auto& it : v){
                pq.push(it);
            }
        }
        return true;
    }
};