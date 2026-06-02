class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>mpp;
        for(auto& ch : tasks){
            mpp[ch]++;
        }
        priority_queue<int>pq ;
        for(auto& it : mpp){
            pq.push(it.second);
        }

        int ans = 0 ;
        while(!pq.empty()){
            vector<int>freqs;
            for(int i = 0 ; i<n+1 ; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    freqs.push_back(freq);
                }
            }

            for(auto& freq : freqs){
                if(freq!=0){
                    pq.push(freq);
                }
            }

            if(pq.empty()){
                ans+=(freqs.size());
            }
            else{
                ans+=(n+1);
            }
        }
        return ans;
    }
};