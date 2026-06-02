class Solution {
public:
    typedef pair<int, int> pi ;
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;

        unordered_map<int, int>mpp;
        for(int i = 0 ; i<hand.size() ; i++){
            mpp[hand[i]]++;
        }
        priority_queue<pi, vector<pi>, greater<pi>>pq;
        for(auto& it : mpp){
            pq.push({it.first, it.second});
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            vector<pair<int, int>>v;
            int s = it.first ;
            int freq = it.second-1 ;
            if(freq != 0){
                v.push_back({s, freq});
            }

            for(int i = s+1 ; i<s+groupSize ; i++){
                if(pq.top().first != i){
                    return false;
                }
                else{
                    auto p = pq.top();
                    pq.pop();
                    if(p.second-1 != 0){
                        v.push_back({p.first, p.second-1});
                    }
                }
            }

            for(auto& pa : v){
                pq.push(pa);
            }
        }
        return true;
    }
};