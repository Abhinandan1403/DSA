class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<long long, vector<long long>, greater<long long>>pq2;
        unsigned long long val = mass ;
        for(int i = 0 ; i<asteroids.size() ; i++){
            if(asteroids[i]<=mass){
                val += asteroids[i] ;
            }
            else{
                pq2.push(asteroids[i]);
            }
        }

        while(!pq2.empty()){
            int wt = pq2.top();
            pq2.pop();
            if(wt>val){
                return false ;
            }
            else{
                val += wt;
            }
        }

        return pq2.empty();
    }
};